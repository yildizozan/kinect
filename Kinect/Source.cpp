// Standard lib
#include <iostream>
#include <math.h>
#include <Windows.h>

// OpenGL
#include <gl\glut.h>

// Nui Api
#include "NuiApi.h"

// My Header
#include "Kinect.h"

OzansKinect::Kinect kinect;

void drawBones(Vector4 start, Vector4 finish)
{
	glVertex2f(start.x, start.y);
	glVertex2f(finish.x, finish.y);
}

void drawHead(float cx, float cy, float r, int num_segments)
{
	float theta = 2 * 3.1415926 / float(num_segments);
	float c = cosf(theta);//precalculate the sine and cosine
	float s = sinf(theta);
	float t;

	float x = r;//we start at angle = 0 
	float y = 0;

	glBegin(GL_LINE_LOOP);
	for (int ii = 0; ii < num_segments; ii++)
	{
		glVertex2f(x + cx, y + cy);//output vertex 

								   //apply the rotation matrix
		t = x;
		x = c * x - s * y;
		y = s * t + c * y;
	}
	glEnd();
}

void drawHead2(float x, float y)
{
	glPointSize(60);
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void render()
{
	kinect.Process();

	Vector4 organ;

	glClear(GL_COLOR_BUFFER_BIT);

	// Draw head
	//drawHead(kinect.getOrgans(NUI_SKELETON_POSITION_HEAD).x, kinect.getOrgans(NUI_SKELETON_POSITION_HEAD).y, 10.0, 360);
	drawHead2(kinect.getOrgans(NUI_SKELETON_POSITION_HEAD).x, kinect.getOrgans(NUI_SKELETON_POSITION_HEAD).y);

	// Draw nodes
	glPointSize(5);
	glBegin(GL_POINTS);
	for (int i = 0; i < NUI_SKELETON_POSITION_COUNT; i++)
	{
		organ = kinect.getOrgans(i);
		if (i != NUI_SKELETON_POSITION_HEAD)
			glVertex2f(organ.x, organ.y);
	}
	glEnd();

	// Draw bones
	glBegin(GL_LINES);
	
	// Head
	glColor3f(1.0, 1.0, 1.0);
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_HEAD), kinect.getOrgans(NUI_SKELETON_POSITION_SHOULDER_CENTER));
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_SHOULDER_CENTER), kinect.getOrgans(NUI_SKELETON_POSITION_SHOULDER_LEFT));
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_SHOULDER_CENTER), kinect.getOrgans(NUI_SKELETON_POSITION_SHOULDER_RIGHT));

	// Arms color
	glColor3f(1.0, 0.0, 0.0);

	// Left arm
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_SHOULDER_LEFT), kinect.getOrgans(NUI_SKELETON_POSITION_ELBOW_LEFT));
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_ELBOW_LEFT), kinect.getOrgans(NUI_SKELETON_POSITION_WRIST_LEFT));
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_WRIST_LEFT), kinect.getOrgans(NUI_SKELETON_POSITION_HAND_LEFT));

	// Right arm
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_SHOULDER_RIGHT), kinect.getOrgans(NUI_SKELETON_POSITION_ELBOW_RIGHT));
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_ELBOW_RIGHT), kinect.getOrgans(NUI_SKELETON_POSITION_WRIST_RIGHT));
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_WRIST_RIGHT), kinect.getOrgans(NUI_SKELETON_POSITION_HAND_RIGHT));

	// Center body
	glColor3f(1.0, 1.0, 1.0);
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_SHOULDER_CENTER), kinect.getOrgans(NUI_SKELETON_POSITION_SPINE));
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_SPINE), kinect.getOrgans(NUI_SKELETON_POSITION_HIP_CENTER));
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_HIP_CENTER), kinect.getOrgans(NUI_SKELETON_POSITION_HIP_LEFT));
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_HIP_CENTER), kinect.getOrgans(NUI_SKELETON_POSITION_HIP_RIGHT));

	// Leg color
	glColor3f(0.0, 1.0, 0.0);

	// Left leg
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_HIP_LEFT), kinect.getOrgans(NUI_SKELETON_POSITION_KNEE_LEFT));
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_KNEE_LEFT), kinect.getOrgans(NUI_SKELETON_POSITION_ANKLE_LEFT));
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_ANKLE_LEFT), kinect.getOrgans(NUI_SKELETON_POSITION_FOOT_LEFT));

	// Right leg
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_HIP_RIGHT), kinect.getOrgans(NUI_SKELETON_POSITION_KNEE_RIGHT));
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_KNEE_RIGHT), kinect.getOrgans(NUI_SKELETON_POSITION_ANKLE_RIGHT));
	drawBones(kinect.getOrgans(NUI_SKELETON_POSITION_ANKLE_RIGHT), kinect.getOrgans(NUI_SKELETON_POSITION_FOOT_RIGHT));

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