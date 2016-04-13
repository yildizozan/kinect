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


void ozansKinect::KinectMotion::showCoord(Vector4 data)
{
	cout << "W: " << data.w << endl;
	cout << "X: " << data.x << endl;
	cout << "Y: " << data.y << endl;
	cout << "Z: " << data.z << endl;
	cout << endl;

	return;
}

void ozansKinect::KinectMotion::showAllOrgans(Vector4 data[])
{
	//Head
	head	=	data[NUI_SKELETON_POSITION_HEAD];

	// Left arm
	shoulderLeft	=	data[NUI_SKELETON_POSITION_SHOULDER_LEFT];
	elbowLeft		=	data[NUI_SKELETON_POSITION_ELBOW_LEFT];
	wristLeft		=	data[NUI_SKELETON_POSITION_WRIST_LEFT];
	handLeft		=	data[NUI_SKELETON_POSITION_HAND_LEFT];

	// Right arm
	shoulderRight	=	data[NUI_SKELETON_POSITION_SHOULDER_RIGHT];
	elbowRight		=	data[NUI_SKELETON_POSITION_ELBOW_RIGHT];
	wristRight		=	data[NUI_SKELETON_POSITION_WRIST_RIGHT];
	handRight		=	data[NUI_SKELETON_POSITION_HAND_RIGHT];

	// Middle body
	shoulderCenter	=	data[NUI_SKELETON_POSITION_SHOULDER_CENTER];
	spine			=	data[NUI_SKELETON_POSITION_SPINE];
	hipCenter		=	data[NUI_SKELETON_POSITION_HIP_CENTER];

	// Left leg
	hipLeft		=	data[NUI_SKELETON_POSITION_HIP_LEFT];
	kneeLeft	=	data[NUI_SKELETON_POSITION_KNEE_LEFT];
	ankleLeft	=	data[NUI_SKELETON_POSITION_ANKLE_LEFT];
	footLeft	=	data[NUI_SKELETON_POSITION_FOOT_LEFT];

	// Right leg
	hipRight	=	data[NUI_SKELETON_POSITION_HIP_RIGHT];
	kneeRight	=	data[NUI_SKELETON_POSITION_KNEE_RIGHT];
	ankleRight	=	data[NUI_SKELETON_POSITION_ANKLE_RIGHT];
	footRight	=	data[NUI_SKELETON_POSITION_FOOT_RIGHT];


	// Coord
	cout << "shoulderLeft" << endl;
	showCoord(shoulderLeft);
	cout << "elbowLeft" << endl;
	showCoord(elbowLeft);
	cout << "wristLeft" << endl;
	showCoord(wristLeft);
	cout << "handLeft" << endl;
	showCoord(handLeft);
/*
	cout << "shoulderRight" << endl;
	showCoord(shoulderRight);
	cout << "elbowRight" << endl;
	showCoord(elbowRight);
	cout << "wristRight" << endl;
	showCoord(wristRight);
	cout << "handRight" << endl;
	showCoord(handRight);
*/
	return;
}

BOOL ozansKinect::KinectMotion::sitDown(Vector4 data[])
{
	hipCenter = data[NUI_SKELETON_POSITION_HIP_CENTER];
	hipLeft = data[NUI_SKELETON_POSITION_HIP_LEFT];
	hipRight = data[NUI_SKELETON_POSITION_HIP_RIGHT];

	cout << "Sit Down" << endl;
	cout << (int)hipCenter.y	<< endl;
	cout << (int)hipLeft.y	<< endl;
	cout << (int)hipRight.y	<< endl;

	return 0;
}

/*
Vector4 hipCenter = getCoordinate2Sens(skeletonData.SkeletonPositions[NUI_SKELETON_POSITION_HIP_CENTER]);
Vector4 hipLeft = getCoordinate2Sens(skeletonData.SkeletonPositions[NUI_SKELETON_POSITION_HIP_LEFT]);
Vector4 hipRight = getCoordinate2Sens(skeletonData.SkeletonPositions[NUI_SKELETON_POSITION_HIP_RIGHT]);

cout << "Sit Down" << endl;
cout << hipCenter.y << endl;
cout << hipLeft.y << endl;
cout << hipRight.y << endl;
*/
