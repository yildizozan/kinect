#pragma once

namespace OzansKinect
{
	class Kinect
	{
	public:
		Kinect();
		~Kinect();

		HRESULT Connection();
		bool Process();
		void Training();

	private:
		// Sample numbers
		const unsigned int SAMPLE_NUMBER = 5000;

		// Kinect sensor pointer
		INuiSensor* mNuiSensor;

		// Storage for organs coordinates
		OzansOrgans::Organ* organs;
		OzansOrgans::Organ* refrence;

	};
}