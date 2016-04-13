/*
*	Author: Ozan YILDIZ
*/
#ifndef KINECTPROCESS_H
#define KINECTPROCESS_H

#define LATENCY 0

#include "KinectMotion.h"

namespace ozansKinect
{
	class KinectProcess : public KinectMotion
	{

	public:

		KinectProcess();
		~KinectProcess();

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

#endif // !KINECTPROCESS_H


