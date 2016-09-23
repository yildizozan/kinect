// Standard lib
#include <iostream>
#include <vector>
#include <Windows.h>
#include <fstream>

// Nui Api
#include "NuiApi.h"

// My Header
#include "Organs.h"
#include "Kinect.h"

using namespace OzansOrgans;

Organs::Organs()
{

}

Organs::Organs(const Organs &newOrgans)
{
	this->head = newOrgans.head;
	this->shoulderCenter = newOrgans.shoulderCenter;

	this->shoulderLeft = newOrgans.shoulderLeft;
	this->elbowLeft = newOrgans.elbowLeft;
	this->wristLeft = newOrgans.wristLeft;
	this->handLeft = newOrgans.handLeft;

	this->shoulderRight = newOrgans.shoulderRight;
	this->elbowRight = newOrgans.elbowRight;
	this->wristRight = newOrgans.wristRight;
	this->handRight = newOrgans.handRight;

	this->spine = newOrgans.spine;
	this->hipCenter = newOrgans.hipCenter;

	this->hipLeft = newOrgans.hipLeft;
	this->kneeLeft = newOrgans.kneeLeft;
	this->ankleLeft = newOrgans.ankleLeft;
	this->footLeft = newOrgans.footLeft;

	this->hipRight = newOrgans.hipRight;
	this->kneeRight = newOrgans.kneeRight;
	this->ankleRight = newOrgans.ankleRight;
	this->footRight = newOrgans.footRight;
}

OzansOrgans::Organs::Organs(const NUI_SKELETON_DATA &pSkeletonData)
{
	setCoordinates(pSkeletonData);
}


Organs::~Organs()
{

}

void OzansOrgans::Organs::setCoordinates(const NUI_SKELETON_DATA &pSkeletonData)
{
	for (int i = 0; i < NUI_SKELETON_POSITION_COUNT; i++)
	{
		Vector4 data = pSkeletonData.SkeletonPositions[i];
		switch (i)
		{
		case NUI_SKELETON_POSITION_HEAD:
			this->head.push_back(data);
			break;
		case NUI_SKELETON_POSITION_SHOULDER_CENTER:
			this->shoulderCenter.push_back(data);
			break;
		case NUI_SKELETON_POSITION_SHOULDER_LEFT:
			this->shoulderLeft.push_back(data);
			break;
		case NUI_SKELETON_POSITION_ELBOW_LEFT:
			this->elbowLeft.push_back(data);
			break;
		case NUI_SKELETON_POSITION_WRIST_LEFT:
			this->wristLeft.push_back(data);
			break;
		case NUI_SKELETON_POSITION_HAND_LEFT:
			this->handLeft.push_back(data);
			break;
		case NUI_SKELETON_POSITION_SHOULDER_RIGHT:
			this->shoulderRight.push_back(data);
			break;
		case NUI_SKELETON_POSITION_ELBOW_RIGHT:
			this->elbowRight.push_back(data);
			break;
		case NUI_SKELETON_POSITION_WRIST_RIGHT:
			this->wristRight.push_back(data);
			break;
		case NUI_SKELETON_POSITION_HAND_RIGHT:
			this->handRight.push_back(data);
			break;
		case NUI_SKELETON_POSITION_SPINE:
			this->spine.push_back(data);
			break;
		case NUI_SKELETON_POSITION_HIP_CENTER:
			this->hipCenter.push_back(data);
			break;
		case NUI_SKELETON_POSITION_HIP_LEFT:
			this->hipLeft.push_back(data);
			break;
		case NUI_SKELETON_POSITION_KNEE_LEFT:
			this->kneeLeft.push_back(data);
			break;
		case NUI_SKELETON_POSITION_ANKLE_LEFT:
			this->ankleLeft.push_back(data);
			break;
		case NUI_SKELETON_POSITION_FOOT_LEFT:
			this->footLeft.push_back(data);
			break;
		case NUI_SKELETON_POSITION_HIP_RIGHT:
			this->hipRight.push_back(data);
			break;
		case NUI_SKELETON_POSITION_KNEE_RIGHT:
			this->kneeRight.push_back(data);
			break;
		case NUI_SKELETON_POSITION_ANKLE_RIGHT:
			this->ankleRight.push_back(data);
			break;
		case NUI_SKELETON_POSITION_FOOT_RIGHT:
			this->footRight.push_back(data);
			break;
		}
	}
}

void OzansOrgans::Organs::allClear(void)
{
	this->head.clear();
	this->shoulderCenter.clear();
	this->shoulderLeft.clear();
	this->elbowLeft.clear();
	this->wristLeft.clear();
	this->handLeft.clear();
	this->shoulderRight.clear();
	this->elbowRight.clear();
	this->wristRight.clear();
	this->handRight.clear();
	this->spine.clear();
	this->hipCenter.clear();
	this->hipLeft.clear();
	this->kneeLeft.clear();
	this->ankleLeft.clear();
	this->footLeft.clear();
	this->hipRight.clear();
	this->kneeRight.clear();
	this->ankleRight.clear();
	this->footRight.clear();
}
