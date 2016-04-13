// Fundamentals
#include <iostream>
using std::cout;
using std::endl;

// Windows headers
#include <Windows.h>

// Kinect Api
#include "NuiApi.h"

// My Classes
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

	cout << "Right Hand" << endl;
	cout << "w: " << (int)rightHand2Sens.w << "\t" << (int)rightHand3Sens.w << endl;
	cout << "x: " << (int)rightHand2Sens.x << "\t" << (int)rightHand3Sens.x << endl;
	cout << "y: " << (int)rightHand2Sens.y << "\t" << (int)rightHand3Sens.y << endl;
	cout << "z: " << (int)rightHand2Sens.z << "\t" << (int)rightHand3Sens.z << endl;

	return;
}

void ozansKinect::Organ::printLeftHandCoord(Vector4 data[])
{

	Vector4 leftHand2Sens = getCoordinate2Sens(data[NUI_SKELETON_POSITION_HAND_RIGHT]);
	Vector4 leftHand3Sens = getCoordinate3Sens(data[NUI_SKELETON_POSITION_HAND_RIGHT]);

	cout << "Left Hand" << endl;
	cout << "w: " << (int)leftHand2Sens.w << "\t" << (int)leftHand3Sens.w << endl;
	cout << "x: " << (int)leftHand2Sens.x << "\t" << (int)leftHand3Sens.x << endl;
	cout << "y: " << (int)leftHand2Sens.y << "\t" << (int)leftHand3Sens.y << endl;
	cout << "z: " << (int)leftHand2Sens.z << "\t" << (int)leftHand3Sens.z << endl;

	return;
}