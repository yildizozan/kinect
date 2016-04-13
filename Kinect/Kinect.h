/*
*	Author: Ozan YILDIZ
*/
#ifndef KINECT_H
#define KINECT_H

#include "KinectMath.h"
#include "Organ.h"
#include "KinectMotion.h"


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
		void KinectExit(const Vector4 &, const Vector4 &);
		void setKinectShutdown(const bool);
		bool getKinectShutdown() const;

		bool connectionStatus(HRESULT);

		// Gestures
		void rightHandShake(int rightHand[30]);


	private:
		INuiSensor* pNuiSensor;
		bool kinectShutdown;

	};
}

#endif // !KINECT_H


