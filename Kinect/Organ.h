/*
*	Author: Ozan YILDIZ
*/
#ifndef ORGAN_H
#define ORGAN_H

namespace ozansKinect
{
	class Organ
	{
		friend class KinectMotion;

	public:
		Organ();
		~Organ();
		void printRightHandCoord(Vector4[]);
		void printLeftHandCoord(Vector4[]);


	private:
		Vector4 skeletonData;
	};
}

#endif // !ORGAN_H

