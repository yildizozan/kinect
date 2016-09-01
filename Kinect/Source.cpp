// Standard lib
#include <iostream>
#include <Windows.h>

// Nui Api
#include "NuiApi.h"

// My Header
#include "Kinect.h"


using namespace OzansKinect;

int main()
{
	Kinect kinect;
	
	HRESULT hr = kinect.Connection();
	if (SUCCEEDED(hr))
	{
		while (1)
			kinect.Process();
	}


	return 0;
}