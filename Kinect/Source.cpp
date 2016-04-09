﻿// KinectProject.cpp : Defines the entry point for the console application.

#include <iostream>
#include <Windows.h>
#include <NuiApi.h>

#include "Kinect.h"

int main()
{
	ozansKinect::Kinect kinect;
	kinect.Initialize();

	// Eğer el hareketi belirtilen coordinatlara gelirse programdan çıkacak.
	while (!kinect.getKinectShutdown())
	{
		kinect.ProcessSkeleton();
		system("cls");
	}

	return 0;
}