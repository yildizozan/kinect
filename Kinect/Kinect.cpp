// Fundamentals
#include <iostream>

// Windows headers
#include <Windows.h>

// Kinect Api
#include "NuiApi.h"

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
	for (DWORD i = 0; i < iSensorCount; i++)
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
				// We're traking the right hand and left hand skeleton, write coordinate
				analysisDataHandLeft = setCoordinate2Sens(skeletonFrame.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT]);
				analysisDataHandRight = setCoordinate2Sens(skeletonFrame.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT]);

				std::cout << std::endl;
				std::cout << (int)analysisDataHandRight.x << " - " << (int)analysisDataHandRight.y << std::endl;

				KinectExit(analysisDataHandLeft, analysisDataHandRight);

				dizi(skeletonFrame.SkeletonData[i].SkeletonPositions);

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
	const DWORD percent = 10;

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
//	FUNCTION: Coordinate2Sens
//
//	PURPOSE:
//
//	COMMENTS:
//
Vector4 ozansKinect::Kinect::setCoordinate2Sens(Vector4 data)
{
	data.w = data.w * 100;
	data.x = data.x * 100;
	data.y = data.y * 100;
	data.z = data.z * 100;

	return data;
}

//
//	FUNCTION:	Coordinate3Sens
//
//	PURPOSE:	Transform coordinate 3 decimal number
//
//	COMMENTS:	asd
//
Vector4 ozansKinect::Kinect::setCoordinate3Sens(Vector4 data)
{
	data.w = data.w * 100;
	data.x = data.x * 100;
	data.y = data.y * 100;
	data.z = data.z * 100;

	return data;
}

DWORD ozansKinect::Kinect::getCoordinateX() const
{
	return coordinateX;
}

DWORD ozansKinect::Kinect::getCoordinateY() const
{
	return coordinateY;
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



//
//	FUNCTION:	fallibility
//
//	PURPOSE:	Percent of number
//
//	COMMENTS(TR):
//
//		Verilen yanılma paylarına göre sayı arasında bir yerde mi diye control eder.
//
bool ozansKinect::Kinect::fallibility(const DWORD &border, const DWORD &percent, const DWORD &current)
{
	if ((border - percent) <= current && current <= (border + percent))
		return true;

	return false;
}

bool ozansKinect::Kinect::fallibility(const DWORD &border, const DWORD &percent, const Vector4 &organ)

{
	if ((border - percent) <= organ.x && organ.x <= (border + percent))
		if ((border - percent) <= organ.y && organ.y <= (border + percent))
			return true;

	return false;
}

void ozansKinect::Kinect::dizi(Vector4 a[])
{
	Vector4 rightHand = setCoordinate2Sens(a[NUI_SKELETON_POSITION_HAND_RIGHT]);
	std::cout << "w: " << rightHand.w << std::endl
		<< "x: " << rightHand.x << std::endl
		<< "y: " << rightHand.y << std::endl
		<< "z: " << rightHand.z << std::endl;

	return;
}