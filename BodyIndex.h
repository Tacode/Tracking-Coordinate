#pragma once
#include <Kinect.h>
#include <cv.h>
#include <opencv2\highgui\highgui.hpp>

#include <qdebug.h>
#include "Depth.h"
using namespace cv;
using namespace std;

class BodyIndex
{
public:
	BodyIndex();
	~BodyIndex();
	HRESULT InitBodyIndex(IKinectSensor *);
	Mat BodyIndex::updateBodyIndex(Mat &IndexImg);
	double *DrawRec(Mat thresholdImage, Mat &cameraFeed, UINT16 *pixData);
private:
	IBodyIndexFrameReader *pBodyIndexFrameReader;
	IBodyIndexFrameSource *pBodyIndexFrameSource;
	HRESULT hr;
	int height=424;
	int width = 512;
	//Mat IndexImg = Mat::zeros(height, width, CV_8UC3);
	Mat thresholdImage = Mat::zeros(height, width, CV_8UC3);	
	double *location =new double[3];
	int count = 0;
};

