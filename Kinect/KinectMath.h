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

		// Math
		virtual bool fallibility(const int &, const int &, const int &);
		virtual bool fallibility(const int &, const int &, const Vector4 &);

		// Coordinate Converter 2 and 3 Degree Sensitive Methods set/get
		virtual Vector4 getCoordinate2Sens(Vector4);
		virtual Vector4 getCoordinate3Sens(Vector4);

		// One axis convert 2 and 3 Degree
		virtual int getCoordinate2Sens(float);
		virtual int getCoordinate3Sens(float);

		// Setter and Getter for private
		void setCoordinateW(int newW);
		int getCoordinateW() const;

		void setCoordinateX(int newX);
		int getCoordinateX() const;

		void setCoordinateY(int newY);
		int getCoordinateY() const;

		void setCoordinateZ(int newZ);
		int getCoordinateZ() const;

		void setData4(Vector4 newZ);
		Vector4 getData4() const;

	private:
		int coordinateW;
		int coordinateX;
		int coordinateY;
		int coordinateZ;

		Vector4 data4;
	};
}

#endif // !KINECTMATH_H