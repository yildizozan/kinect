/*
*	Author: Ozan YILDIZ
*/
#ifndef KINECT_H
#define KINECT_H

#include "KinectMath.h"
#include "Organ.h"

#define LATENCY 5000

namespace ozansKinect
{
	class Kinect : public Organ
	{

	public:

		Kinect();
		~Kinect();

		HRESULT Initialize();
		void ProcessSkeleton();
		// Kinect Shutdown Methods and Variable
		void KinectExit(const Vector4[]);
		void setKinectShutdown(const bool);
		bool getKinectShutdown() const;

		bool connectionStatus(HRESULT);

	private:
		INuiSensor*		pNuiSensor;
		HANDLE			hNextSkeletonEvent;

		bool			kinectShutdown;

	};
}

#endif // !KINECT_H


