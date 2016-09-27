#pragma once

namespace OzansMotions
{
	class Motion
	{
	public:
		Motion(const OzansOrgans::Organ &);
		~Motion();

		void setJumpData(const OzansOrgans::Organ &);
		OzansOrgans::Organ getJumpData(void) const;

		void setHandShakeData(const OzansOrgans::Organ &);
		OzansOrgans::Organ getHandShakeData(void) const;

		// Training data with OpenCV 3.1
		// Machine Learning with SVM
		bool trainHandShake();

		// Result
		float predict(const std::vector<Vector4> &, const float);

	private:
		static const unsigned int FEATURE = 3;

		OzansOrgans::Organ mRefrence;
		OzansOrgans::Organ mJump;
		OzansOrgans::Organ mHandShake;

		cv::Ptr<cv::ml::SVM> svm;


		// Uncoplete function
		cv::Mat createMatrix(unsigned int pRow, unsigned int pColumn, int pType, OzansOrgans::Organ organ);
	};
}
