// KinectProject.cpp : Defines the entry point for the console application.

#include <iostream>
#include <Windows.h>
#include <NuiApi.h>

#include "KinectProcess.h"

int main()
{
	ozansKinect::KinectProcess kinect;
	kinect.Initialize();

	// Eðer el hareketi belirtilen coordinatlara gelirse programdan çýkacak.
	kinect.ProcessSkeleton();

	return 0;
}