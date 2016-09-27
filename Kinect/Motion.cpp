// Standard lib
#include <iostream>
#include <vector>
#include <Windows.h>

// OpenCV 3.1
#include <opencv2/core.hpp>
#include <opencv2/ml.hpp>

// Nui Api
#include "NuiApi.h"

// My Header
#include "Organ.h"
#include "Motion.h"
#include "Kinect.h"




OzansMotions::Motion::Motion(const OzansOrgans::Organ &pRefrence)
	:mRefrence(pRefrence)
{
}

OzansMotions::Motion::~Motion()
{
}

void OzansMotions::Motion::setJumpData(const OzansOrgans::Organ &pmJumpData)
{
	this->mJump = pmJumpData;
}

OzansOrgans::Organ OzansMotions::Motion::getJumpData(void) const
{
	return this->mJump;
}

void OzansMotions::Motion::setHandShakeData(const OzansOrgans::Organ &pmHandShakeData)
{
	this->mHandShake = pmHandShakeData;
}

OzansOrgans::Organ OzansMotions::Motion::getHandShakeData(void) const
{
	return this->mHandShake;
}

/*
* OpenCV 3.1
* Using Machine Learning with SVM
*/
bool OzansMotions::Motion::trainHandShake()
{
	try
	{
		// Labels
		int labels[OzansKinect::Kinect::SAMPLE_COUNT * 2];
		for (unsigned int i = 0; i < OzansKinect::Kinect::SAMPLE_COUNT * 2; i++)
			if (i < OzansKinect::Kinect::SAMPLE_COUNT)
				labels[i] = 0;
			else
				labels[i] = 1;

		cv::Mat labelsMat(OzansKinect::Kinect::SAMPLE_COUNT * 2, 1, CV_32SC1, labels);

		// Add refrence data into the matrix
		float trainingData[OzansKinect::Kinect::SAMPLE_COUNT * 2][3];
		for (unsigned int i = 0; i < OzansKinect::Kinect::SAMPLE_COUNT; i++)
		{
			trainingData[i][0] = this->mRefrence.getHandRight().at(i).x;
			trainingData[i][1] = this->mRefrence.getHandRight().at(i).y;
			trainingData[i][2] = -1;
		}

		for (unsigned int i = OzansKinect::Kinect::SAMPLE_COUNT; i < OzansKinect::Kinect::SAMPLE_COUNT * 2; i++)
		{
			// Add handshake data into the matrix
			trainingData[i][0] = this->mHandShake.getHandRight().at(i - OzansKinect::Kinect::SAMPLE_COUNT).x;
			trainingData[i][2] = this->mHandShake.getHandRight().at(i - OzansKinect::Kinect::SAMPLE_COUNT).y;
			trainingData[i][2] = NUI_SKELETON_POSITION_HAND_RIGHT;

		}
		cv::Mat trainingDataMat(OzansKinect::Kinect::SAMPLE_COUNT * 2, FEATURE, CV_32FC1, trainingData);

		// Train with SVM
		cv::Ptr<cv::ml::SVM> svm = cv::ml::SVM::create();
		svm->setType(cv::ml::SVM::C_SVC);
		svm->setKernel(cv::ml::SVM::LINEAR);
		svm->setTermCriteria(cv::TermCriteria(cv::TermCriteria::MAX_ITER, 100, 1e-6));
		svm->train(trainingDataMat, cv::ml::ROW_SAMPLE, labelsMat);

		this->svm = svm;
	}
	catch(cv::Exception e)
	{
		return false;
	}

	return true;
}

float OzansMotions::Motion::predict(const std::vector<Vector4> &pData, const float pOrgans)
{
	float testData[OzansKinect::Kinect::TEST_SAMPLE_COUNT][3];
	for (unsigned int i = 0; i < OzansKinect::Kinect::TEST_SAMPLE_COUNT; i++)
	{
		testData[i][0] = pData[i].x;
		testData[i][1] = pData[i].y;
		testData[i][2] = pOrgans;
	}

	cv::Mat testDataMat(1, 3, CV_32FC1, testData);
	
	return this->svm->predict(testDataMat);
}