// Fundamentals
#include <iostream>

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

	Vector4 rightHand = getCoordinate2Sens(data[NUI_SKELETON_POSITION_HAND_RIGHT]);

	std::cout	<< "w: " << (int)rightHand.w << std::endl
				<< "x: " << (int)rightHand.x << std::endl
				<< "y: " << (int)rightHand.y << std::endl
				<< "z: " << (int)rightHand.z << std::endl;

	return;
}

void ozansKinect::Organ::printLeftHandCoord(Vector4 data[])
{

	Vector4 leftHand = getCoordinate2Sens(data[NUI_SKELETON_POSITION_HAND_LEFT]);

	std::cout	<< "w: " << (int)leftHand.w << std::endl
				<< "x: " << (int)leftHand.x << std::endl
				<< "y: " << (int)leftHand.y << std::endl
				<< "z: " << (int)leftHand.z << std::endl;

	return;
}