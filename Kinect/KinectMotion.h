/*
*	Author: Ozan YILDIZ
*/

#ifndef KINECTMOTION_H
#define KINECTMOTION_H

#include "KinectMath.h"

namespace ozansKinect
{
	class KinectMotion : public KinectMath
	{
	public:
		KinectMotion();
		~KinectMotion();

		virtual BOOL sitDown(Vector4[]);

	private:
		Vector4 hipCenter;
		Vector4 hipLeft;
		Vector4 hipRight;

	};
}

#endif // !KINECTMOTION_H


