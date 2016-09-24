#pragma once
namespace OzansOrgans
{
	class Organ
	{
	public:
		Organ();
		Organ(const Organ &);	// Copy constructor
		Organ(const NUI_SKELETON_DATA &);
		~Organ();

		// General functions
		void setCoordinates(const NUI_SKELETON_DATA &);
		size_t getOrgansSize() const { return this->head.size(); };
		void allClear(void);

		// Setter & Getters
		void setHead(std::vector<Vector4> head) { this->head = head; }
		std::vector<Vector4> getHead() const { return this->head; }
		void setShoulderCenter(std::vector<Vector4> shoulderCenter) { this->shoulderCenter = shoulderCenter; }
		std::vector<Vector4> getShoulderCenter() const { return this->shoulderCenter; }
		void setShoulderLeft(std::vector<Vector4> shoulderLeft) { this->shoulderLeft = shoulderLeft; }
		std::vector<Vector4> getShoulderLeft() const { return this->shoulderLeft; }
		void setElbowLeft(std::vector<Vector4> elbowLeft) { this->elbowLeft = elbowLeft; }
		std::vector<Vector4> getElbowLeft() const { return this->elbowLeft; }
		void setWristLeft(std::vector<Vector4> wristLeft) { this->wristLeft = wristLeft; }
		std::vector<Vector4> getWristLeft() const { return this->wristLeft; }
		void setHandLeft(std::vector<Vector4> handLeft) { this->handLeft = handLeft; }
		std::vector<Vector4> getHandLeft() const { return this->handLeft; }
		void setShoulderRight(std::vector<Vector4> shoulderRight) { this->shoulderRight = shoulderRight; }
		std::vector<Vector4> getShoulderRight() const { return this->shoulderRight; }
		void setElbowRight(std::vector<Vector4> elbowRight) { this->elbowRight = elbowRight; }
		std::vector<Vector4> getElbowRight() const { return this->elbowRight; }
		void setWristRight(std::vector<Vector4> wristRight) { this->wristRight = wristRight; }
		std::vector<Vector4> getWristRight() const { return this->wristRight; }
		void setHandRight(std::vector<Vector4> handRight) { this->handRight = handRight; }
		std::vector<Vector4> getHandRight() const { return this->handRight; }
		void setSpine(std::vector<Vector4> spine) { this->spine = spine; }
		std::vector<Vector4> getSpine() const { return this->spine; }
		void setHipCenter(std::vector<Vector4> hipCenter) { this->hipCenter = hipCenter; }
		std::vector<Vector4> getHipCenter() const { return this->hipCenter; }
		void setHipLeft(std::vector<Vector4> hipLeft) { this->hipLeft = hipLeft; }
		std::vector<Vector4> getHipLeft() const { return this->hipLeft; }
		void setKneeLeft(std::vector<Vector4> kneeLeft) { this->kneeLeft = kneeLeft; }
		std::vector<Vector4> getKneeLeft() const { return this->kneeLeft; }
		void setAnkleLeft(std::vector<Vector4> ankleLeft) { this->ankleLeft = ankleLeft; }
		std::vector<Vector4> getAnkleLeft() const { return this->ankleLeft; }
		void setFootLeft(std::vector<Vector4> footLeft) { this->footLeft = footLeft; }
		std::vector<Vector4> getFootLeft() const { return this->footLeft; }
		void setHipRight(std::vector<Vector4> hipRight) { this->hipRight = hipRight; }
		std::vector<Vector4> getHipRight() const { return this->hipRight; }
		void setKneeRight(std::vector<Vector4> kneeRight) { this->kneeRight = kneeRight; }
		std::vector<Vector4> getKneeRight() const { return this->kneeRight; }
		void setAnkleRight(std::vector<Vector4> ankleRight) { this->ankleRight = ankleRight; }
		std::vector<Vector4> getAnkleRight() const { return this->ankleRight; }
		void setFootRight(std::vector<Vector4> footRight) { this->footRight = footRight; }
		std::vector<Vector4> getFootRight() const { return this->footRight; }

	private:
		std::vector<Vector4> head;
		std::vector<Vector4> shoulderCenter;

		std::vector<Vector4> shoulderLeft;
		std::vector<Vector4> elbowLeft;
		std::vector<Vector4> wristLeft;
		std::vector<Vector4> handLeft;

		std::vector<Vector4> shoulderRight;
		std::vector<Vector4> elbowRight;
		std::vector<Vector4> wristRight;
		std::vector<Vector4> handRight;

		std::vector<Vector4> spine;
		std::vector<Vector4> hipCenter;

		std::vector<Vector4> hipLeft;
		std::vector<Vector4> kneeLeft;
		std::vector<Vector4> ankleLeft;
		std::vector<Vector4> footLeft;

		std::vector<Vector4> hipRight;
		std::vector<Vector4> kneeRight;
		std::vector<Vector4> ankleRight;
		std::vector<Vector4> footRight;

	};
}