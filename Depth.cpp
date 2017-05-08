#include "Depth.h"
Depth::Depth()
{
}


Depth::~Depth()
{
	SafeRelease(pDepthFrameReader);
}


HRESULT Depth::InitKinect(IKinectSensor *kinect){
	
	pDepthFrameReader = NULL;
	pDepthFrameSource = NULL;
	
	hr = kinect->get_DepthFrameSource(&pDepthFrameSource);
	if (SUCCEEDED(hr)){
		hr = pDepthFrameSource->OpenReader(&pDepthFrameReader);
		if (FAILED(hr)){
			qDebug() << "Can not Open the Reader" << endl;
		}
	}
	SafeRelease(pDepthFrameSource);
	pixData = new UINT16[height*width];
	Capacity = height*width;
	return S_OK;
}

UINT16* Depth::updateDepth(Mat &depthImg){
	IDepthFrame* pDepthFrame = NULL;
	UINT nBufferSize_depth = 0;
	UINT16 *pBuffer_depth = NULL;
	hr = pDepthFrameReader->AcquireLatestFrame(&pDepthFrame);
	if (SUCCEEDED(hr)){
		USHORT nDepthMinReliableDistance = 0;
		USHORT nDepthMaxReliableDistance = 0;
		if (SUCCEEDED(hr))
		{
			hr = pDepthFrame->get_DepthMinReliableDistance(&nDepthMinReliableDistance);
		}

		if (SUCCEEDED(hr))
		{
			hr = pDepthFrame->get_DepthMaxReliableDistance(&nDepthMaxReliableDistance);
		}
		hr = pDepthFrame->AccessUnderlyingBuffer(&nBufferSize_depth, &pBuffer_depth);
		depthImg = ConvertMat(pBuffer_depth, width, height, nDepthMinReliableDistance, nDepthMaxReliableDistance);
		if (SUCCEEDED(hr)){
			//hr = pDepthFrame->CopyFrameDataToArray(Capacity, reinterpret_cast<UINT16 *> (tempImage.data));
			hr = pDepthFrame->CopyFrameDataToArray(Capacity, pixData);

		}
	}
	SafeRelease(pDepthFrame);
	return pixData;
	
}

Mat Depth::ConvertMat(const UINT16* pBuffer, int nWidth, int nHeight, USHORT nMinDepth, USHORT nMaxDepth){
	cv::Mat img(nHeight, nWidth, CV_8UC3);
	uchar* p_mat = img.data;

	const UINT16* pBufferEnd = pBuffer + (nWidth * nHeight);

	while (pBuffer < pBufferEnd)
	{
		USHORT depth = *pBuffer;

		BYTE intensity = static_cast<BYTE>((depth >= nMinDepth) && (depth <= nMaxDepth) ? (depth % 256) : 0);

		*p_mat = intensity;
		p_mat++;
		*p_mat = intensity;
		p_mat++;
		*p_mat = intensity;
		p_mat++;

		++pBuffer;
	}
	return img;

}