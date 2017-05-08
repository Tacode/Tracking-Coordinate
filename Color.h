#pragma once
#include <Kinect.h>
#include <cv.h>
#include <opencv2\highgui\highgui.hpp>
#include <qdebug.h>
#include "Depth.h"
using namespace cv;
using namespace std;
class Color
{
public:
	Color();
	~Color();
	Mat ConvertMat(const RGBQUAD* pBuffer, int nWidth, int nHeight);
	void DrawRec(Mat thresholdImage, Mat &cameraFeed, UINT16 *pixData);
	Mat updateColorImg(Mat & colorImg);
	HRESULT InitColor(IKinectSensor *kinect);
	HRESULT hr;
private:
	IColorFrameReader *pColorFrameReader;
	IColorFrameSource *pColorFrameSource;
	ColorImageFormat imageFormat;
	RGBQUAD* m_pColorRGBX;
	int ColorHeight;
	int ColorWidth;
	Mat colorImg;
	Size dsize = Size(512, 424);
};

