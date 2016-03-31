#include <iostream>
#include <NuiApi.h>

#include "Kinect.h"



Kinect::Kinect()
	:ppNuiSensor(NULL)
{

}


Kinect::~Kinect()
{
}

HRESULT Kinect::Connection()
{
	INuiSensor *pNuiSensor;

	int iNuiSensorCount = 0;
	HRESULT hr = NuiGetSensorCount(&iNuiSensorCount);
	if (FAILED(hr))
	{
		return hr;
	}

	for (int i = 0; i < iNuiSensorCount; ++i)
	{
		// Create the NuiSensor and check,
		// if I can't create it, move on the next
		hr = NuiCreateSensorByIndex(i, &pNuiSensor);
		if (FAILED(hr))
		{
			continue;
		}

		// Get the status of the sensor, and if connected,
		// then we can initialize it
		hr = pNuiSensor->NuiStatus();
		if (S_OK == hr)
		{
			ppNuiSensor = pNuiSensor;
			break;
		}

		// This sensor wasn't OK,
		// release it since we're not using it
		pNuiSensor->Release();
	}

	if (ppNuiSensor != NULL)
	{
		// Initialize the Kinect and specify that we'll be using skeleton
		hr = ppNuiSensor->NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);
	}

	return hr;
}

void Kinect::ProcessSkeleton()
{
	NUI_SKELETON_FRAME skeletonFrame = { 0 };

	HRESULT hr = ppNuiSensor->NuiSkeletonGetNextFrame(1000, &skeletonFrame);
	if (FAILED(hr))
	{
		return;
	}

	ppNuiSensor->NuiTransformSmooth(&skeletonFrame, NULL);

	for (int i = 0; i < NUI_SKELETON_COUNT; i++)
	{
		NUI_SKELETON_TRACKING_STATE trackingState = skeletonFrame.SkeletonData[i].eTrackingState;

		if (NUI_SKELETON_TRACKED == trackingState)
		{
			
			std::cout << skeletonFrame.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].y << std::endl;
		}
	}

}

void Kinect::Update()
{
	if (ppNuiSensor == NULL)
	{
		return;
	}
	ProcessSkeleton();
}


