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

int main(int argc, char** argv)
{
	OzansKinect::Kinect kinect;

	// Train pc
	HRESULT hr = kinect.Connection();
	if (SUCCEEDED(hr))
	{
		kinect.Training();
	}

	system("PAUSE");
	return 0;
}