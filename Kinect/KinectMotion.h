#pragma once
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

	};
}

#endif // !KINECTMOTION_H


