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
		virtual bool fallibility(const int &, const int &, const int &);
		virtual bool fallibility(const int &, const int &, const Vector4 &);

		// Coordinate Converter 2 and 3 Degree Sensitive Methods set/get
		virtual Vector4 getCoordinate2Sens(Vector4);
		virtual Vector4 getCoordinate3Sens(Vector4);

		// One axis convert 2 and 3 Degree
		virtual int getCoordinate2Sens(float);
		virtual int getCoordinate3Sens(float);

	};
}

#endif // !KINECTMATH_H