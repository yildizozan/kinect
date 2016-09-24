// Standard lib
#include <iostream>
#include <vector>
#include <Windows.h>

// Nui Api
#include "NuiApi.h"

// My Header
#include "Organ.h"
#include "Motion.h"
#include "Kinect.h"


OzansKinect::Kinect::Kinect()
	:mNuiSensor(NULL)
{
}


OzansKinect::Kinect::~Kinect()
{
	if (mNuiSensor)
	{
		mNuiSensor->NuiShutdown();
	}
}

// First connection to kinect
HRESULT OzansKinect::Kinect::Connection()
{
	INuiSensor* pNuiSensor;

	int iSensorCount = 0;
	HRESULT hr = NuiGetSensorCount(&iSensorCount);
	if (FAILED(hr))
	{
		return hr;
	}

	// Look at the kinect
	for (int i = 0; i < iSensorCount; ++i)
	{
		// Create a sensor for check
		hr = NuiCreateSensorByIndex(i, &pNuiSensor);
		if (FAILED(hr))
		{
			continue;
		}

		// Get the status sensor
		hr = pNuiSensor->NuiStatus();
		if (S_OK == hr)
		{
			mNuiSensor = pNuiSensor;
			break;
		}

		// We can release temproray variable
		pNuiSensor->Release();
	}

	if (mNuiSensor != NULL)
	{
		// Initialize the Kinect for skeleton mod
		mNuiSensor->NuiInitialize(NUI_INITIALIZE_FLAG_USES_SKELETON);
	}

	if (mNuiSensor == NULL || FAILED(hr))
	{
		std::cout << "Kinect not found!" << std::endl;
		return E_FAIL;
	}

	return hr;
}

bool OzansKinect::Kinect::Process()
{
	NUI_SKELETON_FRAME skeletonFrame;

	HRESULT hr = mNuiSensor->NuiSkeletonGetNextFrame(0, &skeletonFrame);
	if (FAILED(hr))
	{
		false;
	}

	// Smooth skeleton data
	mNuiSensor->NuiTransformSmooth(&skeletonFrame, NULL);

	for (int unsigned i = 0; i < NUI_SKELETON_COUNT; i++)
	{
		NUI_SKELETON_TRACKING_STATE trackingState = skeletonFrame.SkeletonData[i].eTrackingState;
		
		if (trackingState == NUI_SKELETON_TRACKED)
		{
			// Set organs coordinates
			organs->setCoordinates(skeletonFrame.SkeletonData[i]);

			// Write skeleton positions
			for (int j = 0; j < NUI_SKELETON_POSITION_COUNT; j++)
			{
				// Console write coord
				std::cout 
					<< "X:" << skeletonFrame.SkeletonData[i].SkeletonPositions[j].x << " "
					<< "Y:" << skeletonFrame.SkeletonData[i].SkeletonPositions[j].y << " "
					<< ">:" << skeletonFrame.SkeletonData[i].SkeletonPositions[j].z << " " <<
				std::endl;
			}
		}
	}
	system("CLS");

	return true;
}

// Kinect save standart human behavior.
void OzansKinect::Kinect::Training()
{
	// If process capture SAMPLE_NUMBER frame
	// Stop the Process function
	while (Process())
		if (organs->getOrgansSize() == SAMPLE_SIZE)
			break;

	// Pointer assingment
	refrence = organs;

	// Delete temp
	organs->allClear();

	// Jump training
	while (Process())
		if (organs->getOrgansSize() == SAMPLE_SIZE)
		{
			motions->setJumpData(*organs);
			break;
		}
}
