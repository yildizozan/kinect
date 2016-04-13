// Fundamentals
#include <iostream>

// Windows headers
#include <Windows.h>

// Kinect Api
#include "NuiApi.h"

// My Classes
#include "KinectMath.h"


ozansKinect::KinectMath::KinectMath()
	:coordinateW(0), coordinateX(0), coordinateY(0), coordinateZ(0)
{
}

ozansKinect::KinectMath::~KinectMath()
{
}

//
//	FUNCTION:	fallibility
//
//	PURPOSE:	Percent of number
//
//	COMMENTS(TR):
//
//		Verilen yanýlma paylarýna göre sayý arasýnda bir yerde mi diye control eder.
//
bool ozansKinect::KinectMath::fallibility(const int &border, const int &percent, const int &current)
{
	if ((border - percent) <= current && current <= (border + percent))
		return true;

	return false;
}

bool ozansKinect::KinectMath::fallibility(const int &border, const int &percent, const Vector4 &organ)

{
	if ((border - percent) <= organ.x && organ.x <= (percent + border))
		if ((border - percent) <= organ.y && organ.y <= (percent + border))
			return true;

	return false;
}

//
//	FUNCTION: Coordinate2Sens
//
//	PURPOSE:
//
//	COMMENTS:
//
Vector4 ozansKinect::KinectMath::getCoordinate2Sens(Vector4 data)
{
	data.w = data.w * 100;
	data.x = data.x * 100;
	data.y = data.y * 100;
	data.z = data.z * 100;

	return data;
}

Vector4 ozansKinect::KinectMath::getCoordinate3Sens(Vector4 data)
{
	data.w = data.w * 1000;
	data.x = data.x * 1000;
	data.y = data.y * 1000;
	data.z = data.z * 1000;

	return data;
}

int ozansKinect::KinectMath::getCoordinate2Sens(float data)
{
	return (int)data * 100;
}

int ozansKinect::KinectMath::getCoordinate3Sens(float data)
{
	return (int)data * 1000;
}

// Setters and Getters
void ozansKinect::KinectMath::setCoordinateW(int newW)
{
	coordinateW = newW;
}

int ozansKinect::KinectMath::getCoordinateW() const
{
	return 0;
}

void ozansKinect::KinectMath::setCoordinateX(int newX)
{
	coordinateX = newX;
	return;
}

int ozansKinect::KinectMath::getCoordinateX() const
{
	return 0;
}

void ozansKinect::KinectMath::setCoordinateY(int newY)
{
	coordinateY = newY;
	return;
}

int ozansKinect::KinectMath::getCoordinateY() const
{
	return 0;
}

void ozansKinect::KinectMath::setCoordinateZ(int newZ)
{
	coordinateZ = newZ;
	return;
}

int ozansKinect::KinectMath::getCoordinateZ() const
{
	return 0;
}

void ozansKinect::KinectMath::setData4(Vector4 newData4)
{
	data4 = newData4;
	return;
}

Vector4 ozansKinect::KinectMath::getData4() const
{
	return data4;
}

