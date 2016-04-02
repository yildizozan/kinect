#ifndef KINECT_H
#define KINECT_H

namespace ozansKinect
{

#define LATECY 1000

	class Kinect
	{
	public:
		Kinect();
		~Kinect();

		HRESULT Initialize();

		void ProcessSkeleton();

		// Kinect Exit method set/get
		void setKinectExit(const bool x);
		bool getKinectExit() const;

		// Coordinate Converter method set/get
		void setCoordinate2Sens(const double x, const double y);
		void setCoordinate3Sens(const double x, const double y);
		int getCoordinateX() const;
		int getCoordinateY() const;

	private:
		INuiSensor* pNuiSensor;
		bool kinectWorkingStatus;
		int coordinateX, coordinateY;
	};
}

#endif // !KINECT_H



