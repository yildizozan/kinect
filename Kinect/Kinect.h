#pragma once
namespace OzansKinect {
	class Kinect
	{
	private:
		INuiSensor* mNuiSensor;
		Vector4 organs[NUI_SKELETON_POSITION_COUNT];

		//void setCoordinate(const NUI_SKELETON_DATA &);

	public:
		Kinect();
		~Kinect();

		HRESULT Connection();
		HRESULT Process();

		Vector4 getOrgans(int);

	};
}