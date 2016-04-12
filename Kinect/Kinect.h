/*
*	Author: Ozan YILDIZ
*/
#pragma once
#ifndef KINECT_H
#define KINECT_H

#define LATECY 1000

namespace ozansKinect
{
	class Kinect : public Organ,  public KinectMotion
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


