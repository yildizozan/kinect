#pragma once
namespace OzansOrgans
{
	class Organs
	{
	public:
		Organs();
		Organs(const Organs &);	// Copy constructor
		~Organs();
	private:
		// Body top
		std::vector<Vector4> head;
		std::vector<Vector4> shoulderCenter;

		// Arm left
		std::vector<Vector4> shoulderLeft;
		std::vector<Vector4> elbowLeft;
		std::vector<Vector4> wristLeft;
		std::vector<Vector4> handLeft;

		// Arm right
		std::vector<Vector4> shoulderRight;
		std::vector<Vector4> elbowRight;
		std::vector<Vector4> wristRight;
		std::vector<Vector4> handRight;

		// Body buttom 
		std::vector<Vector4> spine;
		std::vector<Vector4> hipCenter;

		// Leg left
		std::vector<Vector4> hipLeft;
		std::vector<Vector4> kneeLeft;
		std::vector<Vector4> ankleLeft;
		std::vector<Vector4> footLeft;

		// Leg right
		std::vector<Vector4> hipRight;
		std::vector<Vector4> kneeRight;
		std::vector<Vector4> ankleRight;
		std::vector<Vector4> footRight;

	};
}