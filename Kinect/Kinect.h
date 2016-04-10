#ifndef KINECT_H
#define KINECT_H

namespace ozansKinect
{

#define LATECY 1000
	struct _coordinate
	{
		DWORD x, y;
	};

	class Kinect
	{

	public:
		Kinect();
		~Kinect();

		Kinect desf()
		{

		}

		HRESULT Initialize();

		void ProcessSkeleton();

		// Kinect Shutdown Methods and Variable
		void KinectExit(const Vector4 &, const Vector4 &);
		void setKinectShutdown(const bool);
		bool getKinectShutdown() const;

		// Coordinate Converter 2 and 3 Degree Sensitive Methods set/get
		Vector4 setCoordinate2Sens(Vector4);
		Vector4 setCoordinate3Sens(Vector4);
		DWORD getCoordinateX() const;
		DWORD getCoordinateY() const;

		bool connectionStatus(HRESULT);

		// Gestures
		void rightHandShake(DWORD rightHand[30]);

		// Math
		bool fallibility(const DWORD &, const DWORD &, const DWORD &);
		bool fallibility(const DWORD &, const DWORD &, const Vector4 &);
		void dizi(Vector4[]);

	private:
		INuiSensor* pNuiSensor;
		bool kinectShutdown;
		DWORD coordinateW, coordinateX, coordinateY, coordinateZ;

		// Private struct example
		_coordinate coordinate;
	};
}

#endif // !KINECT_H


