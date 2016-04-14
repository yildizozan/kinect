/*
*	Author: Ozan YILDIZ
*/
#ifndef KINECTMATH_H
#define KINECTMATH_H

#define ERROR_PERCENT 10

namespace ozansKinect
{
	class KinectMath
	{

	public:
		KinectMath();
		~KinectMath();

		// Fallibility
		bool fallibility(const int &current, const int &border, const int &percentValue);
		bool fallibility(const Vector4 &, const int &, const int &);


		// Coordinate Converter 2 and 3 Degree Sensitive Methods set/get
		Vector4 getCoordinate2Sens(Vector4);
		Vector4 getCoordinate3Sens(Vector4);

		// One axis convert 2 and 3 Degree
		int getCoordinate2Sens(float);
		int getCoordinate3Sens(float);

		bool CompareVector4(const Vector4 &, const Vector4 &, const int);


	};
}

#endif // !KINECTMATH_H