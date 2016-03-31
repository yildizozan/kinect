#include "stdafx.h"
#include "Kinect.h"

int main()
{
	Kinect kinect;
	while (1)
	{
		kinect.Update();
		system("cls");
	}

	NuiShutdown();
	return 0;
}