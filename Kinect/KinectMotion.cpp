#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

// Windows headers
#include <Windows.h>

// Kinect Api
#include "NuiApi.h"

// My Classes
#include "KinectMotion.h"


ozansKinect::KinectMotion::KinectMotion()
{
}


ozansKinect::KinectMotion::~KinectMotion()
{
}

BOOL ozansKinect::KinectMotion::sitDown(Vector4 data[])
{
	hipCenter = data[NUI_SKELETON_POSITION_HIP_CENTER];	//getCoordinate2Sens(data[NUI_SKELETON_POSITION_HIP_CENTER]);
	hipLeft = data[NUI_SKELETON_POSITION_HIP_LEFT];	//getCoordinate2Sens(data[NUI_SKELETON_POSITION_HIP_LEFT]);
	hipRight = data[NUI_SKELETON_POSITION_HIP_LEFT];	//getCoordinate2Sens(data[NUI_SKELETON_POSITION_HIP_LEFT]);

	cout << "Sit Down" << endl;
	cout << hipCenter.y	<< endl;
	cout << hipLeft.y	<< endl;
	cout << hipRight.y	<< endl;

	return 0;
}


