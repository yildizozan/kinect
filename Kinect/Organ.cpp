// Fundamentals
#include <iostream>
using std::cout;
using std::endl;

// Windows headers
#include <Windows.h>

// Kinect Api
#include "NuiApi.h"

// My Classes
#include "KinectMath.h"
#include "Organ.h"



ozansKinect::Organ::Organ()
{
}


ozansKinect::Organ::~Organ()
{
}

void ozansKinect::Organ::printRightHandCoord(Vector4 data[])
{

	Vector4 rightHand2Sens = getCoordinate2Sens(data[NUI_SKELETON_POSITION_HAND_RIGHT]);
	Vector4 rightHand3Sens = getCoordinate3Sens(data[NUI_SKELETON_POSITION_HAND_RIGHT]);


	cout << "w: " << rightHand2Sens.w << "\t" << rightHand3Sens.w << endl
		<< "x: " << rightHand2Sens.x << "\t" << rightHand3Sens.x << endl
		<< "y: " << rightHand2Sens.y << "\t" << rightHand3Sens.y << endl
		<< "z: " << rightHand2Sens.z << "\t" << rightHand3Sens.z << endl;

	return;
}

void ozansKinect::Organ::printLeftHandCoord(Vector4 data[])
{

	Vector4 leftHand2Sens = getCoordinate2Sens(data[NUI_SKELETON_POSITION_HAND_LEFT]);
	Vector4 leftHand3Sens = getCoordinate2Sens(data[NUI_SKELETON_POSITION_HAND_LEFT]);

	cout << "w: " << leftHand2Sens.w << "\t" << leftHand3Sens.w << endl
		<< "x: " << leftHand2Sens.x << "\t" << leftHand3Sens.x << endl
		<< "y: " << leftHand2Sens.y << "\t" << leftHand3Sens.y << endl
		<< "z: " << leftHand2Sens.z << "\t" << leftHand3Sens.z << endl;

	return;
}