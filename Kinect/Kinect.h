#pragma once

namespace OzansKinect
{
	class Kinect
	{
	public:
		static const unsigned int SAMPLE_COUNT = 50;
		static const unsigned int TEST_SAMPLE_COUNT = 7;

		Kinect();
		~Kinect();

		HRESULT Connection();
		bool Training();
		void CheckHandShake();

	private:
		// Sample numbers

		// Kinect sensor pointer
		INuiSensor* mNuiSensor;
		void Process() const;

		// Storage for organs coordinates
		OzansOrgans::Organ* mOrgan;

		// Initialize refrence motions
		OzansMotions::Motion* motions;
	};
}