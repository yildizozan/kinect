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
	hipCenter = getCoordinate2Sens(data[NUI_SKELETON_POSITION_HIP_CENTER]);
	hipLeft = getCoordinate2Sens(data[NUI_SKELETON_POSITION_HIP_LEFT]);
	hipRight = getCoordinate2Sens(data[NUI_SKELETON_POSITION_HIP_RIGHT]);

	cout << "Sit Down" << endl;
	cout << hipCenter.y	<< endl;
	cout << hipLeft.y	<< endl;
	cout << hipRight.y	<< endl;

	return 0;
}


