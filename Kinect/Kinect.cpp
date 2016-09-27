// Standard lib
#include <iostream>
#include <vector>
#include <Windows.h>

// OpenCV 3.1
#include <opencv2/core.hpp>
#include <opencv2/ml.hpp>

// Nui Api
#include "NuiApi.h"

// My Header
#include "Organ.h"
#include "Motion.h"
#include "Kinect.h"


OzansKinect::Kinect::Kinect()
	:mNuiSensor(NULL)
{
	this->mOrgan = new OzansOrgans::Organ;
}


OzansKinect::Kinect::~Kinect()
{
	if (mNuiSensor)
	{
		mNuiSensor->NuiShutdown();
	}

	delete mOrgan;
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

void OzansKinect::Kinect::Process() const
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
			// Set organs coordinates
			mOrgan->addCoordinates(skeletonFrame.SkeletonData[i]);

			// Console write coord
			std::cout
				<< "X:" << skeletonFrame.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].x << " "
				<< "Y:" << skeletonFrame.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].y << " "
				<< ">:" << skeletonFrame.SkeletonData[i].SkeletonPositions[NUI_SKELETON_POSITION_HAND_RIGHT].z << " " <<
			std::endl;
		}
	}
	system("CLS");
}

/*
 * Kinect save standart human behavior.
 * If process capture SAMPLE_COUNT frame
 * Stop the Process() function
 */
bool OzansKinect::Kinect::Training()
{
	// Initialize refrence data
	while (true)
	{
		if (mOrgan->size() != SAMPLE_COUNT)
			Process();
		else
			break;
	}

	// Initialize refrence motions
	motions = new OzansMotions::Motion(*mOrgan);

	// Sleep for next motion
	Sleep(1000);

	// Clear temp data organs
	mOrgan->clear();

	// Initialize handshake data
	while (true)
	{
		if (mOrgan->size() != SAMPLE_COUNT)
			Process();
		else
			break;
	}

	// Set handshake datas
	motions->setHandShakeData(*mOrgan);

	// Clear all temp organ data
	mOrgan->clear();

	// Train hand shake motion
	if (motions->trainHandShake())
	{
		return true;
	}
	else
	{
		return false;
	}
}

void OzansKinect::Kinect::CheckHandShake()
{
	while (true)
	{
		if (mOrgan->size() != TEST_SAMPLE_COUNT)
			Process();
		else
		{
			float response = this->motions->predict(mOrgan->getHandRight(), NUI_SKELETON_POSITION_HAND_RIGHT);
			if (response == 1)
				std::cout << "HankShake High Five!" << std::endl;

			mOrgan->clear();
		}
	}
}

/*
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
 */
