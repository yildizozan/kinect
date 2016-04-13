/*
*	Author: Ozan YILDIZ
*/

#ifndef KINECTMOTION_H
#define KINECTMOTION_H

namespace ozansKinect
{
	class KinectMotion
	{
	public:
		KinectMotion();
		~KinectMotion();

		BOOL sitDown(Vector4 &, Vector4 &, Vector4 &);

	private:
		Vector4 butt;
		Vector4 leftKnee;
		Vector4 rightKnee;

	};
}

#endif // !KINECTMOTION_H


