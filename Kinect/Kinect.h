#pragma once
namespace OzansKinect {
	class Kinect
	{
	private:
		INuiSensor* mNuiSensor;
		NUI_SKELETON_DATA skeletonData;

	public:
		Kinect();
		~Kinect();

		HRESULT Connection();
		HRESULT Process();

		void Draw();
	};
}