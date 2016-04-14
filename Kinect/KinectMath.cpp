// Fundamentals
#include <iostream>

// Windows headers
#include <Windows.h>

// Kinect Api
#include "NuiApi.h"

// My Classes
#include "KinectMath.h"


ozansKinect::KinectMath::KinectMath()
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
bool ozansKinect::KinectMath::fallibility(const int &current, const int &border, const int &percentValue)
{
		int percent = border * percentValue / 100;
	if ((border - percent) <= current && current <= (border + percent))
		return true;

	return false;
}

bool ozansKinect::KinectMath::fallibility(const Vector4 &organ, const int &border, const int &percentValue)
{
	int percent = border * percentValue / 100;
	if ((border - percent) <= organ.x && organ.x <= (percent + border))
		if ((border - percent) <= organ.y && organ.y <= (percent + border))
			return true;

	return false;
}

bool ozansKinect::KinectMath::CompareVector4(const Vector4 &vector1, const Vector4 &vector2, const int fallibility)
{
	if ((vector1.x - (vector1.x * fallibility / 100)) && (vector1.y - (vector1.y * fallibility / 100)))
		if ((vector2.x - (vector2.x * fallibility / 100)) && (vector2.y - (vector2.y * fallibility / 100)))
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
//		
Vector4 ozansKinect::KinectMath::getCoordinate2Sens(Vector4 data)
{
	data.w = (int)data.w * 100;
	data.x = (int)data.x * 100;
	data.y = (int)data.y * 100;
	data.z = (int)data.z * 100;

	return data;
}

Vector4 ozansKinect::KinectMath::getCoordinate3Sens(Vector4 data)
{
	data.w = (int)data.w * 1000;
	data.x = (int)data.x * 1000;
	data.y = (int)data.y * 1000;
	data.z = (int)data.z * 1000;

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
