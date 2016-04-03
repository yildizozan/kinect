// C++ Standart Library
#include <iostream>

// Windows headers
#include <Windows.h>

// Kinect Api
#include "NuiApi.h"

#include "Kinect.h"

ozansKinect::Kinect::Kinect()
	:pNuiSensor(NULL),
	kinectShutdown(false)
{
}


ozansKinect::Kinect::~Kinect()
{
	if (pNuiSensor)
	{
		pNuiSensor->NuiShutdown();
		std::cout << "Bye Bye! :)" << std::endl;
	}
	else if (pNuiSensor == nullptr)
	{
		std::cout << "Kinect not found." << std::endl;
	}
	system("PAUSE");
}
//
//	FUNCTION:	Initialize
//
//	PURPOSE:	
//
//	COMMENTS:	Sisteme takılı olan Kinect sayısına bakacak
//				her Kinect için sırayla bağlanmaya çalışacak,
//				eğer bağlantı sağlanamaz ise bağlı kinect bulamayacak program sonlanacak.
//				Eğer bağlı kinect bulursa o kinect cihazına bağlanacak ve işleme geçecek.
//
void ozansKinect::Kinect::Initialize()
{
	INuiSensor* tempNuiSensor;

	int iSensorCount = 0;

	HRESULT hr = NuiGetSensorCount(&iSensorCount);
	if (connectionStatus(hr)) return;


	// Look at each Kinect sensor
	for (int i = 0; i < iSensorCount; i++)
	{
		// Create the sensor so we can check status,
		// if we can't create it, move on
		hr = NuiCreateSensorByIndex(i, &tempNuiSensor);
		if (connectionStatus(hr)) return;

		// Get the status of the sensor, and if connected
		// then we can initialize it
		hr = tempNuiSensor->NuiStatus();
		if (connectionStatus(hr)) return;
		else
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
		if (connectionStatus(hr)) return;

		hr = pNuiSensor->NuiSkeletonTrackingEnable(NULL, NUI_SKELETON_TRACKING_FLAG_ENABLE_SEATED_SUPPORT);
		if (connectionStatus(hr)) return;
	}

	if (pNuiSensor == nullptr)
	{
		hr = E_FAIL;
		if (connectionStatus(hr)) return;
	}

	return;
}

//
//	FUNCTION:	ProcessSkeleton
//
//	PURPOSE:	
//
//	COMMENTS(TR):
//
void ozansKinect::Kinect::ProcessSkeleton()
{
	while (!getKinectShutdown())
	{
		// Create skeleton frame
		NUI_SKELETON_FRAME skeletonFrame = { 0 };

		// Skeleton data for analysis
		NUI_SKELETON_DATA skeletonData;

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
				skeletonData = skeletonFrame.SkeletonData[i];

				// We're traking and sending skeleton data
				SkeletonPositions(skeletonData);
			}
		}
	}

	return;
}

void ozansKinect::Kinect::SkeletonPositions(const NUI_SKELETON_DATA &skeletonData)
{
	// Exit control
	//if (KinectExit(skeletonData.SkeletonPositions[NUI_SKELETON_POSITION_HAND_LEFT],
		//skeletonData.SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT]))
		///setKinectShutdown(true);

	for (int i = 0; i < NUI_SKELETON_POSITION_COUNT; i++)
	{
		Vector4 skeletonPosition = skeletonData.SkeletonPositions[i];

		std::cout << (int)skeletonPosition.x << " - " << (int)skeletonPosition.y << std::endl << std::endl;
		
	}
}

//
//	FUNCTION:	KinectShutdown
//
//	PURPOSE:	
//
//	COMMENTS(TR):
//
bool ozansKinect::Kinect::KinectExit(const Vector4 &leftHand, const Vector4 &rightHand)
{
	if (-10 <= (int)leftHand.x && (int)leftHand.x <= 10 && -10 <= (int)leftHand.y && (int)leftHand.y <= 10)
		if (-10 <= (int)rightHand.x && (int)rightHand.x <= 10 && -10 <= (int)rightHand.y && (int)rightHand.y <= 10)
			return true;

	return false;
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
//	FUNCTION:	Coordinate2Sens
//
//	PURPOSE:	
//
//	COMMENTS(TR):
//
Vector4 ozansKinect::Kinect::setCoordinate2Sens(Vector4 &data)
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
//	COMMENTS(TR):	asd
//
Vector4 ozansKinect::Kinect::setCoordinate3Sens(Vector4 &data)
{
	data.w = data.w * 1000;
	data.x = data.x * 1000;
	data.y = data.y * 1000;
	data.z = data.z * 1000;

	return data;
}

//
//	FUNCTION:	connectionStatus
//
//	PURPOSE:	
//
//	COMMENTS(TR):
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

bool ozansKinect::Kinect::connectionStatus(bool value)
{
	if (value == true)
		return true;
	else
		return false;
}
