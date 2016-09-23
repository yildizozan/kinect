// Standard lib
#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>

// Nui Api
#include "NuiApi.h"

// My Header
#include "Organs.h"
#include "Kinect.h"

using namespace OzansKinect;

Kinect::Kinect()
	:mNuiSensor(NULL), exit(false)
{
	outputFile = std::ofstream("dataset.txt");
}


Kinect::~Kinect()
{
	if (mNuiSensor)
	{
		mNuiSensor->NuiShutdown();
	}

	outputFile.close();
}

HRESULT Kinect::Connection()
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

NUI_SKELETON_FRAME Kinect::Process()
{
	NUI_SKELETON_FRAME skeletonFrame;

	HRESULT hr = mNuiSensor->NuiSkeletonGetNextFrame(0, &skeletonFrame);
	if (FAILED(hr))
	{
		return;
	}

	// Smooth skeleton data
	mNuiSensor->NuiTransformSmooth(&skeletonFrame, NULL);

	for (int unsigned i = 0; i < NUI_SKELETON_COUNT; i++)
	{
		NUI_SKELETON_TRACKING_STATE trackingState = skeletonFrame.SkeletonData[i].eTrackingState;
		
		if (trackingState == NUI_SKELETON_TRACKED)
		{
			// exit
			//if (organs->getHandRight().size() == 99) exit = true;

			for (int j = 0; j < NUI_SKELETON_POSITION_COUNT; j++)
			{
				// Save organs coordinates
				//organs->setCoord(skeletonFrame.SkeletonData[i].SkeletonPositions[j], j);

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

	return skeletonFrame;
}

bool Kinect::getExit() const
{
	return this->exit;
}