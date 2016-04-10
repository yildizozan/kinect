// Fundamentals
#include <iostream>

// Windows headers
#include <Windows.h>

// Kinect Api
#include "NuiApi.h"

// My Classes
#include "Organ.h"
#include "KinectMath.h"
#include "Kinect.h"

ozansKinect::Kinect::Kinect()
	:pNuiSensor(NULL),
	kinectShutdown(false),
	coordinateX(0), coordinateY(0)
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
	
	Sleep(2000);

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
	for (unsigned int i = 0; i < iSensorCount; i++)
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
	// Kinect Math
	KinectMath KinectMath;
	Organ Organ;

	// Create skeleton frame
	NUI_SKELETON_FRAME skeletonFrame = { 0 };

	// Skeleton data
	NUI_SKELETON_DATA skeletonData; //* Değişecek: 20 sayısının yerine define gelecek

	// Analysis data variable
	Vector4 analysisDataHandRight;
	Vector4 analysisDataHandLeft;

	// Frame Counter
	DWORD frameCounter = 0;
	DWORD frame[30];

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

		for (DWORD i = 0; i < NUI_SKELETON_COUNT; i++)
		{
			NUI_SKELETON_TRACKING_STATE trackingState = skeletonFrame.SkeletonData[i].eTrackingState;

			if (NUI_SKELETON_TRACKED == trackingState)
			{
				// Skeleton data
				skeletonData = skeletonFrame.SkeletonData[i];

				// We're traking the right hand and left hand skeleton, write coordinate
				analysisDataHandLeft = KinectMath.getCoordinate2Sens(skeletonData.SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT]);
				analysisDataHandRight = KinectMath.getCoordinate2Sens(skeletonData.SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT]);

				KinectExit(analysisDataHandLeft, analysisDataHandRight);


				Organ.printLeftHandCoord(skeletonData.SkeletonPositions);
				std::cout << std::endl;
				Organ.printRightHandCoord(skeletonData.SkeletonPositions);

				if (frameCounter == 30)
				{
					rightHandShake(frame);
				}
				else
				{
					frame[frameCounter];
					frameCounter++;
				}

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
	KinectMath KinectMath;

	const DWORD percent = 10;

	if (KinectMath.fallibility(0, percent, leftHand))
		if (KinectMath.fallibility(0, percent, rightHand))
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

void ozansKinect::Kinect::rightHandShake(DWORD rightHand[30])
{
	
	
	return;
}
