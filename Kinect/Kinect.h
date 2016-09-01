#pragma once
namespace OzansKinect {
	class Kinect
	{
	private:
		INuiSensor* mNuiSensor;

	public:
		Kinect();
		~Kinect();

		HRESULT Connection();
		HRESULT Process();
	};
}