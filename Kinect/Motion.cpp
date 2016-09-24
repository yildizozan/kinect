// Standard lib
#include <iostream>
#include <vector>
#include <Windows.h>

// Nui Api
#include "NuiApi.h"

// My Header
#include "Organ.h"
#include "Motion.h"
#include "Kinect.h"


OzansMotions::Motion::Motion()
{
}

OzansMotions::Motion::~Motion()
{
}

void OzansMotions::Motion::setJumpData(const OzansOrgans::Organ pJumpData)
{
	this->jump = pJumpData;
}

OzansOrgans::Organ OzansMotions::Motion::getJumpData(void) const
{
	return this->jump;
}

void OzansMotions::Motion::setHandShakeData(const OzansOrgans::Organ pHandShakeData)
{
	this->handShake = pHandShakeData;
}

OzansOrgans::Organ OzansMotions::Motion::getHandShakeData(void) const
{
	return this->handShake;
}

