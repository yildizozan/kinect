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

		HRESULT Initialize();

		VOID ProcessSkeleton();

		// Kinect Shutdown Methods and Variable
		VOID KinectExit(CONST Vector4 &, CONST Vector4 &);
		VOID setKinectShutdown(CONST BOOL);
		BOOL getKinectShutdown() CONST;

		// Coordinate Converter 2 and 3 Degree Sensitive Methods set/get
		Vector4 setCoordinate2Sens(Vector4);
		Vector4 setCoordinate3Sens(Vector4);
		DWORD getCoordinateX() CONST;
		DWORD getCoordinateY() CONST;

		BOOL connectionStatus(HRESULT);

		// Gestures
		VOID rightHandShake(DWORD rightHand[30]);

		// Math
		BOOL fallibility(CONST DWORD &, CONST DWORD &, CONST DWORD &);
		BOOL fallibility(CONST DWORD &, CONST DWORD &, CONST Vector4 &);
	private:
		INuiSensor* pNuiSensor;
		BOOL kinectShutdown;
		DWORD coordinateW, coordinateX, coordinateY, coordinateZ;

		// Private struct example
		_coordinate coordinate;
	};
}

#endif // !KINECT_H


