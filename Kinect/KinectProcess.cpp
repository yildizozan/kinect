// Fundamentals
#include <iostream>
using std::cout;
using std::endl;

#include <vector>

// Windows headers
#include <Windows.h>

// Kinect Api
#include "NuiApi.h"

// My Classes
#include "KinectMath.h"
#include "KinectMotion.h"
#include "KinectProcess.h"

using namespace ozansKinect;

ozansKinect::KinectProcess::KinectProcess()
	:pNuiSensor(NULL),
	kinectShutdown(false)
{

} // end constructor


ozansKinect::KinectProcess::~KinectProcess()
{

	if (pNuiSensor)
	{
		pNuiSensor->NuiShutdown();

		cout << "Bye bye.." << endl;

	}

	if (pNuiSensor == nullptr)
	{
		cout << "Kinect not found." << endl;
	}

	Sleep(3000);

} // end destructors

  //
  //	FUNCTION:	Initialize
  //
  //	PURPOSE:	
  //
  //	COMMENTS(TR):
  //
  //		Sisteme takılı olan Kinect sayısına bakacak
  //		her Kinect için sýrayla baðlanmaya çalýþacak,
  //		eðer baðlantý saðlanamaz ise baðlý kinect bulamayacak program sonlanacak.
  //		Eðer baðlý kinect bulursa o kinect cihazýna baðlanacak ve işleme geçecek.
HRESULT ozansKinect::KinectProcess::Initialize()
{
	INuiSensor* tempNuiSensor;

	int iSensorCount = 0;

	HRESULT hr = NuiGetSensorCount(&iSensorCount);
	if (FAILED(hr))
	{
		return hr;
	}

	// Look at each Kinect sensor
	for (int i = 0; i < iSensorCount; i++)
	{
		// Create the sensor so we can check status,
		// if we can't create it, move on
		hr = NuiCreateSensorByIndex(i, &tempNuiSensor);
		if (FAILED(hr))
		{
			continue;
		}

		// Get the status of the sensor, and if connected
		// then we can initialize it
		hr = tempNuiSensor->NuiStatus();
		if (S_OK == hr)
		{
			pNuiSensor = tempNuiSensor;
			break;
		}

		// This sensor wasn't OK,
		// so release it since we're not using it
		tempNuiSensor->Release();
	}

	// If its working
	if (pNuiSensor != NULL)
	{
		hr = pNuiSensor->NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);
		if (SUCCEEDED(hr))
		{
			// Create an event that will be signaled when skeleton data is available
			hNextSkeletonEvent = CreateEventW(NULL, TRUE, TRUE, NULL);

			hr = pNuiSensor->NuiSkeletonTrackingEnable(hNextSkeletonEvent, NUI_SKELETON_TRACKING_FLAG_SUPPRESS_NO_FRAME_DATA);
			cout << "Success" << endl;
		}
	}

	if (pNuiSensor == nullptr)
	{
		hr = E_FAIL;
		return hr;
	}

	return hr;

} // end function Initialize

  //
  //	FUNCTION: ProcessSkeleton
  //
  //	PURPOSE:
  //
  //	COMMENTS:
  //
void ozansKinect::KinectProcess::ProcessSkeleton()

	// Starting to tracking
	while (!getKinectShutdown())
	{
		if (WAIT_OBJECT_0 == WaitForSingleObject(hNextSkeletonEvent, 0))
		{
			// Create skeleton frame
			NUI_SKELETON_FRAME skeletonFrame = { 0 };

			// Get the skeleton frame is ready
			HRESULT hr = pNuiSensor->NuiSkeletonGetNextFrame(LATENCY, &skeletonFrame);
			if (SUCCEEDED(hr))
			{
				// Smooth skeleton data
				pNuiSensor->NuiTransformSmooth(&skeletonFrame, NULL);

				// Starting to data
				for (int i = 0; i < NUI_SKELETON_COUNT; i++)
				{
					NUI_SKELETON_TRACKING_STATE trackingState = skeletonFrame.SkeletonData[i].eTrackingState;

					if (NUI_SKELETON_TRACKED == trackingState)
					{
						// Skeleton data
						NUI_SKELETON_DATA skeletonData = skeletonFrame.SkeletonData[i];

						cout << skeletonData.SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].x << " - "
							<< skeletonData.SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT].x << endl;
						// We're traking the right hand and left hand skeleton for exit
						//KinectExit(skeletonData.SkeletonPositions);
						KinectMotion motion(skeletonData.SkeletonPositions);
						//motion.setOrgan(skeletonData.SkeletonPositions);
						motion.showAllOrgans();


					} // end if
				} // end for
			}
		}
		system("CLS");
	} // end while
} // end function

//
//	FUNCTION: KinectShutdown
//
//	PURPOSE:
//
//	COMMENTS:
//		
//		Gelen data da sag ve sol elin koordinatlarina gore ikiside sifir noktasina gelir ise
//		program cikisi saglayacak.
//
void ozansKinect::KinectProcess::KinectExit(const Vector4 data[])
{
	KinectMath math;

	Vector4 dataHandLeft = math.getCoordinate3Sens(data[NUI_SKELETON_POSITION_HAND_LEFT]);
	Vector4 dataHandRight = math.getCoordinate3Sens(data[NUI_SKELETON_POSITION_HAND_RIGHT]);

	if (math.fallibility(dataHandLeft, 0, ERROR_PERCENT))
		if (math.fallibility(dataHandRight, 0, ERROR_PERCENT))
			setKinectShutdown(true);

	return;
}

void ozansKinect::KinectProcess::setKinectShutdown(const bool value)
{
	kinectShutdown = value;
}

bool ozansKinect::KinectProcess::getKinectShutdown() const
{
	return kinectShutdown;
}



//
//	FUNCTION: hrControl
//
//	PURPOSE:
//
//	COMMENTS:
//
bool ozansKinect::KinectProcess::connectionStatus(HRESULT hr)
{
	if (FAILED(hr))
	{
		setKinectShutdown(true);
		return true;
	}

	return false;
}

