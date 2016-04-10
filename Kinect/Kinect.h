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

		void ProcessSkeleton();

		// Kinect Shutdown Methods and Variable
		void KinectExit(const Vector4 &, const Vector4 &);
		void setKinectShutdown(const bool);
		bool getKinectShutdown() const;

		bool connectionStatus(HRESULT);

		// Gestures
		void rightHandShake(DWORD rightHand[30]);



	private:
		INuiSensor* pNuiSensor;
		bool kinectShutdown;
		DWORD coordinateW, coordinateX, coordinateY, coordinateZ;

		// Private struct example
		_coordinate coordinate;
	};
}

#endif // !KINECT_H


