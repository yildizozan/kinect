/*
*	Author: Ozan YILDIZ
*/
#ifndef KINECTMATH_H
#define KINECTMATH_H

namespace ozansKinect
{
	class KinectMath
	{

	public:
		KinectMath();
		~KinectMath();

		// Fallibility
		bool fallibility(const int &, const int &, const int &);
		bool fallibility(const int &, const int &, const Vector4 &);

		// Coordinate Converter 2 and 3 Degree Sensitive Methods set/get
		Vector4 getCoordinate2Sens(Vector4);
		Vector4 getCoordinate3Sens(Vector4);

		// One axis convert 2 and 3 Degree
		int getCoordinate2Sens(float);
		int getCoordinate3Sens(float);

	};
}

#endif // !KINECTMATH_H