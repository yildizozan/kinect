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

		bool getExit() const;

		OzansOrgans::Organs getOrgans() { this->organs; };
	private:
		// Sample numbers
		const unsigned int SAMPLE_NUMBER = 5000;

		// Finish the process loop
		bool exit;

		// Kinect sensor pointer
		INuiSensor* mNuiSensor;

		// Storage for organs
		OzansOrgans::Organs* organs;

	};
}