/*
*	Author: Ozan YILDIZ
*/

#ifndef KINECTMOTION_H
#define KINECTMOTION_H

#define ERROR_PERCENT 1

namespace ozansKinect
{
	class KinectMotion
	{
	public:
		KinectMotion();
		~KinectMotion();

		// Showing
		void showAllOrgans(Vector4[]);

		// Motions
		void sitDown();

		// Set and Get
		void setOrgan(Vector4 data[]);
		Vector4 getOrgan(const int) const;

	protected:
		// Math
		Vector4 getVector4Coord3Sens(Vector4 &);
		bool CompareVector4(const Vector4 &, const Vector4 &, const int);
		void showCoord(Vector4 &);

	private:
		// Head
		Vector4 head;

		// Left arm
		Vector4 shoulderLeft;
		Vector4 elbowLeft;
		Vector4 wristLeft;
		Vector4 handLeft;

		// Right arm
		Vector4 shoulderRight;
		Vector4 elbowRight;
		Vector4 wristRight;
		Vector4 handRight;

		// Middle body
		Vector4 shoulderCenter;
		Vector4 spine;
		Vector4 hipCenter;

		// Left Leg
		Vector4 hipLeft;
		Vector4 kneeLeft;
		Vector4 ankleLeft;
		Vector4 footLeft;

		// Right Leg
		Vector4 hipRight;
		Vector4 kneeRight;
		Vector4 ankleRight;
		Vector4 footRight;

	};
}

#endif // !KINECTMOTION_H


