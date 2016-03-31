#pragma once
class Kinect
{
public:
	Kinect();
	~Kinect();
	HRESULT Connection();
	void ProcessSkeleton();
	void Update();

private:
	INuiSensor *ppNuiSensor;
};

