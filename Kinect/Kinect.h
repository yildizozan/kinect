#ifndef KINECT_H
#define KINECT_H

namespace ozansKinect
{

#define LATECY 0

	class Kinect
	{

	public:
		Kinect();
		~Kinect();
		
		void Initialize();
		void ProcessSkeleton();
		void SkeletonPositions(const NUI_SKELETON_DATA &);

		// Kinect Shutdown Methods and Variable
		bool KinectExit(const Vector4 &, const Vector4 &);
		void setKinectShutdown(const bool);
		bool getKinectShutdown() const;

		// Coordinate Converter 2 and 3 Degree Sensitive Methods set/get
		Vector4 setCoordinate2Sens(Vector4 &);
		Vector4 setCoordinate3Sens(Vector4 &);

		bool connectionStatus(HRESULT);
		bool connectionStatus(bool);

	private:
		INuiSensor* pNuiSensor;
		bool kinectShutdown;

	};
}

#endif // !KINECT_H



