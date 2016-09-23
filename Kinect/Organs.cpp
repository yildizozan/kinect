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


Organs::~Organs()
{

}