// Standard lib
#include <iostream>
#include <Windows.h>

// OpenGL
#include <gl\glut.h>

// Nui Api
#include "NuiApi.h"

// My Header
#include "Kinect.h"

using namespace OzansKinect;

Kinect kinect;

void render() {
	kinect.Process();

	Vector4 organ;

	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(5);
	glBegin(GL_POINTS);

	for (int i = 0; i < NUI_SKELETON_POSITION_COUNT; i++)
	{
		organ = kinect.getOrgans(i);
		glVertex2d(organ.x, organ.y);
	}
	glEnd();

	glFlush();
}

int main(int argc, char ** argv)
{
	HRESULT hr = kinect.Connection();
	if (SUCCEEDED(hr))
	{
		glutInit(&argc, argv);
		glutInitWindowSize(800, 600);   // Set the window's initial width & height
		glutCreateWindow("Skeleton");
		glutIdleFunc(render);
		glutMainLoop();
	}

	return 0;
}