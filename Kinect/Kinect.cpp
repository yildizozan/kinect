// Fundamentals
#include <iostream>

// Windows headers
#include <Windows.h>

// Kinect Api
#include "NuiApi.h"

// My Classes
#include "KinectMath.h"
#include "Organ.h"
#include "Kinect.h"

ozansKinect::Kinect::Kinect()
	:pNuiSensor(NULL),
	kinectShutdown(false)
{

} // end constructor


ozansKinect::Kinect::~Kinect()
{
	if (pNuiSensor)
	{
		pNuiSensor->NuiShutdown();

		std::cout << "Bye bye.." << std::endl;

	}

	if (pNuiSensor == nullptr)
	{
		std::cout << "Kinect not found." << std::endl;
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
//		her Kinect için sırayla bağlanmaya çalışacak,
//		eğer bağlantı sağlanamaz ise bağlı kinect bulamayacak program sonlanacak.
//		Eğer bağlı kinect bulursa o kinect cihazına bağlanacak ve işleme geçecek.
HRESULT ozansKinect::Kinect::Initialize()
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

	if (pNuiSensor != NULL)
	{
		hr = pNuiSensor->NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);
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
void ozansKinect::Kinect::ProcessSkeleton()
{
	// Create skeleton frame
	NUI_SKELETON_FRAME skeletonFrame = { 0 };

	// Skeleton data
	NUI_SKELETON_DATA skeletonData;

	// Analysis data variable
	Vector4 analysisDataHandRight;
	Vector4 analysisDataHandLeft;

	// Frame Counter
	int frameCounter = 0;
	int frame[30];

	while (!getKinectShutdown())
	{
		// Prepare next frame
		HRESULT hr = pNuiSensor->NuiSkeletonGetNextFrame(LATECY, &skeletonFrame);
		if (FAILED(hr))
		{
			return;
		}

		// Smooth skeleton data
		pNuiSensor->NuiTransformSmooth(&skeletonFrame, NULL);

		for (int i = 0; i < NUI_SKELETON_COUNT; i++)
		{
			NUI_SKELETON_TRACKING_STATE trackingState = skeletonFrame.SkeletonData[i].eTrackingState;

			if (NUI_SKELETON_TRACKED == trackingState)
			{
				// Skeleton data
				skeletonData = skeletonFrame.SkeletonData[i];

				// We're traking the right hand and left hand skeleton, write coordinate
				analysisDataHandLeft = getCoordinate2Sens(skeletonData.SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT]);
				analysisDataHandRight = getCoordinate2Sens(skeletonData.SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT]);

				KinectExit(analysisDataHandLeft, analysisDataHandRight);

				printLeftHandCoord(skeletonData.SkeletonPositions);
				std::cout << std::endl;
				printRightHandCoord(skeletonData.SkeletonPositions);

/*				if (frameCounter == 30)
				{
					rightHandShake(frame);
				}
				else
				{
					frame[frameCounter];
					frameCounter++;
				}
*/
			} // end if

		} // end for

		// We can see koord
		system("cls");

	} // end while

	return;
}

//
//	FUNCTION: KinectShutdown
//
//	PURPOSE:
//
//	COMMENTS:
//
void ozansKinect::Kinect::KinectExit(const Vector4 &leftHand, const Vector4 &rightHand)
{
	const int percent = 10;

	if (fallibility(0, percent, leftHand))
		if (fallibility(0, percent, rightHand))
			setKinectShutdown(true);

	return;
}

void ozansKinect::Kinect::setKinectShutdown(const bool value)
{
	kinectShutdown = value;
}

bool ozansKinect::Kinect::getKinectShutdown() const
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
bool ozansKinect::Kinect::connectionStatus(HRESULT hr)
{
	if (FAILED(hr))
	{
		setKinectShutdown(true);
		return true;
	}

	return false;
}

void ozansKinect::Kinect::rightHandShake(int rightHand[30])
{
	
	
	return;
}
