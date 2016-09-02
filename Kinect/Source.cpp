// Standard lib
#include <iostream>
#include <Windows.h>

// OpenGL
#include <gl/glut.h>

// Nui Api
#include "NuiApi.h"

// My Header
#include "Kinect.h"

using namespace OzansKinect;

int main(int argc, char ** argv)
{
	glutInit(&argc, argv);
	glutCreateWindow("First Window");
	glutInitWindowSize(1024, 768);

	Kinect kinect;

	HRESULT hr = kinect.Connection();
	if (SUCCEEDED(hr))
	{
		glutDisplayFunc(kinect.Draw);
	}

	glutMainLoop();

	return 0;
}