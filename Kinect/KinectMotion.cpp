#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

// Windows headers
#include <Windows.h>

// Kinect Api
#include "NuiApi.h"

// My Classes
#include "KinectMath.h"
#include "KinectMotion.h"


ozansKinect::KinectMotion::KinectMotion()
{
}

ozansKinect::KinectMotion::KinectMotion(Vector4 data[])
{
	for (unsigned int i = 0; i < 20; i++)
	{
		switch (i)
		{
			// Head
		case NUI_SKELETON_POSITION_HEAD:
			head = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_HEAD]);
			break;
			// Arm left
		case NUI_SKELETON_POSITION_SHOULDER_LEFT:
			shoulderLeft = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_SHOULDER_LEFT]);
			break;
		case NUI_SKELETON_POSITION_ELBOW_LEFT:
			elbowLeft = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_ELBOW_LEFT]);
			break;
		case NUI_SKELETON_POSITION_WRIST_LEFT:
			wristLeft = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_WRIST_LEFT]);
			break;
		case NUI_SKELETON_POSITION_HAND_LEFT:
			handLeft = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_HAND_LEFT]);
			break;
			// Arm right
		case NUI_SKELETON_POSITION_SHOULDER_RIGHT:
			shoulderRight = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_SHOULDER_RIGHT]);
			break;
		case NUI_SKELETON_POSITION_ELBOW_RIGHT:
			elbowRight = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_ELBOW_RIGHT]);
			break;
		case NUI_SKELETON_POSITION_WRIST_RIGHT:
			wristRight = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_WRIST_RIGHT]);
			break;
		case NUI_SKELETON_POSITION_HAND_RIGHT:
			handRight = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_HAND_RIGHT]);
			break;
			// Center of body
		case NUI_SKELETON_POSITION_SHOULDER_CENTER:
			shoulderCenter = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_SHOULDER_CENTER]);
			break;
		case NUI_SKELETON_POSITION_SPINE:
			spine = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_SPINE]);
			break;
		case NUI_SKELETON_POSITION_HIP_CENTER:
			hipCenter = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_HIP_CENTER]);
			break;
			// Leg left
		case NUI_SKELETON_POSITION_HIP_LEFT:
			hipLeft = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_HIP_LEFT]);
			break;
		case NUI_SKELETON_POSITION_KNEE_LEFT:
			kneeLeft = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_KNEE_LEFT]);
			break;
		case NUI_SKELETON_POSITION_ANKLE_LEFT:
			ankleLeft = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_ANKLE_LEFT]);
			break;
		case NUI_SKELETON_POSITION_FOOT_LEFT:
			footLeft = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_FOOT_LEFT]);
			break;
			// Leg right
		case NUI_SKELETON_POSITION_HIP_RIGHT:
			hipRight = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_HIP_RIGHT]);
			break;
		case NUI_SKELETON_POSITION_KNEE_RIGHT:
			kneeRight = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_KNEE_RIGHT]);
			break;
		case NUI_SKELETON_POSITION_ANKLE_RIGHT:
			ankleRight = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_ANKLE_RIGHT]);
			break;
		case NUI_SKELETON_POSITION_FOOT_RIGHT:
			footRight = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_FOOT_RIGHT]);
			break;
		default:
			break;
		}
	}
}



ozansKinect::KinectMotion::~KinectMotion()
{
}

void ozansKinect::KinectMotion::showAllOrgans()
{
/*
	//Head
	head = data[NUI_SKELETON_POSITION_HEAD];

	// Left arm
	shoulderLeft = data[NUI_SKELETON_POSITION_SHOULDER_LEFT];
	elbowLeft = data[NUI_SKELETON_POSITION_ELBOW_LEFT];
	wristLeft = data[NUI_SKELETON_POSITION_WRIST_LEFT];
	handLeft = data[NUI_SKELETON_POSITION_HAND_LEFT];

	// Right arm
	shoulderRight = data[NUI_SKELETON_POSITION_SHOULDER_RIGHT];
	elbowRight = data[NUI_SKELETON_POSITION_ELBOW_RIGHT];
	wristRight = data[NUI_SKELETON_POSITION_WRIST_RIGHT];
	handRight = data[NUI_SKELETON_POSITION_HAND_RIGHT];

	// Middle body
	shoulderCenter = data[NUI_SKELETON_POSITION_SHOULDER_CENTER];
	spine = data[NUI_SKELETON_POSITION_SPINE];
	hipCenter = data[NUI_SKELETON_POSITION_HIP_CENTER];

	// Left leg
	hipLeft = data[NUI_SKELETON_POSITION_HIP_LEFT];
	kneeLeft = data[NUI_SKELETON_POSITION_KNEE_LEFT];
	ankleLeft = data[NUI_SKELETON_POSITION_ANKLE_LEFT];
	footLeft = data[NUI_SKELETON_POSITION_FOOT_LEFT];

	// Right leg
	hipRight = data[NUI_SKELETON_POSITION_HIP_RIGHT];
	kneeRight = data[NUI_SKELETON_POSITION_KNEE_RIGHT];
	ankleRight = data[NUI_SKELETON_POSITION_ANKLE_RIGHT];
	footRight = data[NUI_SKELETON_POSITION_FOOT_RIGHT];
*/
	/*
	// Coord
	cout << "shoulderLeft" << endl;
	showCoord(shoulderLeft);
	cout << "elbowLeft" << endl;
	showCoord(elbowLeft);
	cout << "wristLeft" << endl;
	showCoord(wristLeft);
	cout << "handLeft" << endl;
	showCoord(handLeft);
	*/

	cout << "shoulderRight" << endl;
	showCoord(shoulderRight);
	cout << "elbowRight" << endl;
	showCoord(elbowRight);
	cout << "wristRight" << endl;
	showCoord(wristRight);
	cout << "handRight" << endl;
	showCoord(handRight);

	return;
}

void ozansKinect::KinectMotion::setOrgan(Vector4 data[])
{
	for (int i = 0; i < 20; i++)
	{
		switch (i)
		{
		// Head
		case NUI_SKELETON_POSITION_HEAD:
			head = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_HEAD]);
			break;
		// Arm left
		case NUI_SKELETON_POSITION_SHOULDER_LEFT:
			shoulderLeft = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_SHOULDER_LEFT]);
			break;
		case NUI_SKELETON_POSITION_ELBOW_LEFT:
			elbowLeft = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_ELBOW_LEFT]);
			break;
		case NUI_SKELETON_POSITION_WRIST_LEFT:
			wristLeft = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_WRIST_LEFT]);
			break;
		case NUI_SKELETON_POSITION_HAND_LEFT:
			handLeft = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_HAND_LEFT]);
			break;
		// Arm right
		case NUI_SKELETON_POSITION_SHOULDER_RIGHT:
			shoulderRight = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_SHOULDER_RIGHT]);
			break;
		case NUI_SKELETON_POSITION_ELBOW_RIGHT:
			elbowRight = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_ELBOW_RIGHT]);
			break;
		case NUI_SKELETON_POSITION_WRIST_RIGHT:
			wristRight = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_WRIST_RIGHT]);
			break;
		case NUI_SKELETON_POSITION_HAND_RIGHT:
			handRight = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_HAND_RIGHT]);
			break;
		// Center of body
		case NUI_SKELETON_POSITION_SHOULDER_CENTER:
			shoulderCenter = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_SHOULDER_CENTER]);
			break;
		case NUI_SKELETON_POSITION_SPINE:
			spine = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_SPINE]);
			break;
		case NUI_SKELETON_POSITION_HIP_CENTER:
			hipCenter = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_HIP_CENTER]);
			break;
		// Leg left
		case NUI_SKELETON_POSITION_HIP_LEFT:
			hipLeft = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_HIP_LEFT]);
			break;
		case NUI_SKELETON_POSITION_KNEE_LEFT:
			kneeLeft = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_KNEE_LEFT]);
			break;
		case NUI_SKELETON_POSITION_ANKLE_LEFT:
			ankleLeft = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_ANKLE_LEFT]);
			break;
		case NUI_SKELETON_POSITION_FOOT_LEFT:
			footLeft = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_FOOT_LEFT]);
			break;
		// Leg right
		case NUI_SKELETON_POSITION_HIP_RIGHT:
			hipRight = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_HIP_RIGHT]);
			break;
		case NUI_SKELETON_POSITION_KNEE_RIGHT:
			kneeRight = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_KNEE_RIGHT]);
			break;
		case NUI_SKELETON_POSITION_ANKLE_RIGHT:
			ankleRight = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_ANKLE_RIGHT]);
			break;
		case NUI_SKELETON_POSITION_FOOT_RIGHT:
			footRight = getVector4Coord3Sens(data[NUI_SKELETON_POSITION_FOOT_RIGHT]);
			break;
		default:
			break;
		}
	}
	return;
}

Vector4 ozansKinect::KinectMotion::getOrgan(const int organ) const
{
	switch (organ)
	{
		// Head
	case NUI_SKELETON_POSITION_HEAD:
		return head;
		// Arm left
	case NUI_SKELETON_POSITION_SHOULDER_LEFT:
		return shoulderLeft;
	case NUI_SKELETON_POSITION_ELBOW_LEFT:
		return elbowLeft;
	case NUI_SKELETON_POSITION_WRIST_LEFT:
		return wristLeft;
	case NUI_SKELETON_POSITION_HAND_LEFT:
		return handLeft;
		// Arm right
	case NUI_SKELETON_POSITION_SHOULDER_RIGHT:
		return shoulderRight;
	case NUI_SKELETON_POSITION_ELBOW_RIGHT:
		return elbowRight;
	case NUI_SKELETON_POSITION_WRIST_RIGHT:
		return wristRight;
	case NUI_SKELETON_POSITION_HAND_RIGHT:
		return handRight;
		// Center of body
	case NUI_SKELETON_POSITION_SHOULDER_CENTER:
		return shoulderCenter;
	case NUI_SKELETON_POSITION_SPINE:
		return spine;
	case NUI_SKELETON_POSITION_HIP_CENTER:
		return hipCenter;
		// Leg left
	case NUI_SKELETON_POSITION_HIP_LEFT:
		return hipLeft;
	case NUI_SKELETON_POSITION_KNEE_LEFT:
		return kneeLeft;
	case NUI_SKELETON_POSITION_ANKLE_LEFT:
		return ankleLeft;
	case NUI_SKELETON_POSITION_FOOT_LEFT:
		return footLeft;
		// Leg right
	case NUI_SKELETON_POSITION_HIP_RIGHT:
		return hipRight;
	case NUI_SKELETON_POSITION_KNEE_RIGHT:
		return kneeRight;
	case NUI_SKELETON_POSITION_ANKLE_RIGHT:
		return ankleRight;
	case NUI_SKELETON_POSITION_FOOT_RIGHT:
		return footRight;
	default:
		cout << "Error" << endl;
		return Vector4();
	}
}

void ozansKinect::KinectMotion::sitDown()
{
	cout << "Sit Down" << endl;
	showCoord(hipCenter);
	showCoord(hipLeft);
	showCoord(hipRight);

	if (CompareVector4(hipLeft, hipRight, PERCENT))
		cout << "Oturiyin" << endl;

	return;
}

Vector4 ozansKinect::KinectMotion::getVector4Coord3Sens(Vector4 &data)
{
	data.w = data.w * 1000;
	data.x = data.x * 1000;
	data.y = data.y * 1000;
	data.z = data.z * 1000;

	return data;
}

bool ozansKinect::KinectMotion::CompareVector4(const Vector4 &vector1, const Vector4 &vector2, const int fallibility)
{
	if ((vector1.x - (vector1.x * fallibility / 100)) && (vector1.y - (vector1.y * fallibility / 100)))
		if ((vector2.x - (vector2.x * fallibility / 100)) && (vector2.y - (vector2.y * fallibility / 100)))
			return true;

	return false;
}

void ozansKinect::KinectMotion::showCoord(Vector4 &data)
{
	cout << "W: " << data.w << endl;
	cout << "X: " << data.x << endl;
	cout << "Y: " << data.y << endl;
	cout << "Z: " << data.z << endl;
	cout << endl;

	return;
}
