#ifndef KINECTMATH_H
#define KINECTMATH_H

namespace ozansKinect
{
	class KinectMath
	{
		friend class Kinect;
		friend class Organ;

	public:
		KinectMath();
		~KinectMath();

		// Math
		bool fallibility(const DWORD &, const DWORD &, const DWORD &);
		bool fallibility(const DWORD &, const DWORD &, const Vector4 &);

		// Coordinate Converter 2 and 3 Degree Sensitive Methods set/get
		Vector4 getCoordinate2Sens(Vector4 &);
		Vector4 getCoordinate3Sens(Vector4 &);

		void setCoordinateW(int newW);
		int getCoordinateW() const;

		void setCoordinateX(int newX);
		int getCoordinateX() const;

		void setCoordinateY(int newY);
		int getCoordinateY() const;

		void setCoordinateZ(int newZ);
		int getCoordinateZ() const;

	private:
		int coordinateW;
		int coordinateX;
		int coordinateY;
		int coordinateZ;
	};
}

#endif // !KINECTMATH_H