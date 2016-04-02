// Fundamentals
#include <iostream>

// Windows headers
#include <Windows.h>

// Kinect Api
#include "NuiApi.h"

#include "Kinect.h"

ozansKinect::Kinect::Kinect()
	:pNuiSensor(NULL),
	kinectWorkingStatus(true),
	coordinateX(0), coordinateY(0)
{
}


ozansKinect::Kinect::~Kinect()
{
	pNuiSensor->NuiShutdown();
	//pNuiSensor = nullptr; // neden olmuyor ?
}

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
			return hr;
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
		if (SUCCEEDED(hr))
		{
			return hr;
		}
	}

	// Always success for create kinect
	return hr;
}

void ozansKinect::Kinect::ProcessSkeleton()
{
	// Create skeleton frame
	NUI_SKELETON_FRAME skeletonFrame = { 0 };

	// Analysis array
	Vector4 analysisDataHandRight;

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
			// We're traking the right hand skeleton, write coordinate
			analysisDataHandRight = skeletonFrame.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT];

			setCoordinate2Sens(analysisDataHandRight.x, analysisDataHandRight.y);
			std::cout << getCoordinateX() << std::endl << getCoordinateY() << std::endl;
			if (getCoordinateY() == 0 && getCoordinateX() == 0)
			{
				setKinectExit(false);
			}
			// setCoordinate2Sens() BURADAN DEVAM *********************
		}
	}

	return;
}

void ozansKinect::Kinect::setKinectExit(const bool x)
{
	kinectWorkingStatus = x;
}

bool ozansKinect::Kinect::getKinectExit() const
{
	return kinectWorkingStatus;
}

void ozansKinect::Kinect::setCoordinate2Sens(const double x, const double y)
{
	coordinateX = x * 100;
	coordinateY = y * 100;
}

void ozansKinect::Kinect::setCoordinate3Sens(const double x, const double y)
{
	coordinateX = x * 1000;
	coordinateY = y * 1000;

}

int ozansKinect::Kinect::getCoordinateX() const
{
	return coordinateX;
}

int ozansKinect::Kinect::getCoordinateY() const
{
	return coordinateY;
}
