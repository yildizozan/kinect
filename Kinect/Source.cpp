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

int main(int argc, char** argv)
{
	OzansKinect::Kinect kinect;

	// Train pc
	HRESULT hr = kinect.Connection();
	if (SUCCEEDED(hr))
	{
		kinect.Training();
	}

	kinect.CheckHandShake();

	system("PAUSE");
	return 0;
}