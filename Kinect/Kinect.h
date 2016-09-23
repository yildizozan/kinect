#pragma once

namespace OzansKinect
{
	class Kinect
	{
	private:
		bool exit;

		// Kinect sensor pointer
		INuiSensor* mNuiSensor;

		// Storage for organs
		OzansOrgans::Organs* organs;
		std::ofstream outputFile;
	public:
		Kinect();
		~Kinect();

		HRESULT Connection();
		void Process();

		bool getExit() const;

		OzansOrgans::Organs getOrgans() { this->organs; };

	};
}