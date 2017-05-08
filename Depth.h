#pragma once
#include <Kinect.h>
#include <cv.h>
#include <opencv2\highgui\highgui.hpp>
#include <qdebug.h>
using namespace cv;
using namespace std;
template<class Interface>
inline void SafeRelease(Interface *& pInterfaceToRelease)
{
	if (pInterfaceToRelease != NULL)
	{
		pInterfaceToRelease->Release();
		pInterfaceToRelease = NULL;
	}
}



class Depth
{
public:
	Depth();
	~Depth();
	HRESULT InitKinect(IKinectSensor *kinect);
	Mat ConvertMat(const UINT16* pBuffer, int nWidth, int nHeight, USHORT nMinDepth, USHORT nMaxDepth);
	UINT16 * updateDepth(Mat &depthImg);
private:
	HRESULT hr;
	int height = 424;
	int width = 512;
	IDepthFrameReader *pDepthFrameReader;
	IDepthFrameSource *pDepthFrameSource;
	UINT Capacity;
	UINT16 * pixData;
	Mat depthImg = Mat::zeros(height, width, CV_8UC3);
};

