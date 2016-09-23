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