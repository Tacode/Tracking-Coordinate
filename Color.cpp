#include "Color.h"


Color::Color()
{
}


Color::~Color()
{
	SafeRelease(pColorFrameReader);
}

HRESULT Color::InitColor(IKinectSensor* kinect){
	pColorFrameSource = NULL;
	pColorFrameReader = NULL;
	/*��ʼ��RGB����ͷ*/
	hr = kinect->get_ColorFrameSource(&pColorFrameSource);
	if (!SUCCEEDED(hr)){
		cout << "��ȡColorԴʧ��" << endl;
		return E_FAIL;
	}
	hr = pColorFrameSource->OpenReader(&pColorFrameReader);
	if (!SUCCEEDED(hr)){
		cout << "��color��ȡ��ʧ��" << endl;
		return E_FAIL;
	}
	SafeRelease(pColorFrameSource);
	ColorHeight =1080;
	ColorWidth = 1920;
	m_pColorRGBX = new RGBQUAD[ColorWidth * ColorHeight];
	colorImg.create(ColorHeight, ColorWidth,CV_8UC3);

	return S_OK;
}

Mat Color::updateColorImg(Mat & NewColorImage){
	IColorFrame * pColorFrame = NULL;
	/*Colorͼ���ȡ����ʾ*/
	UINT nBufferSize_color = 0;
	RGBQUAD *pBuffer_color = NULL;
	hr = pColorFrameReader->AcquireLatestFrame(&pColorFrame);

	if (SUCCEEDED(hr))
	{
		imageFormat = ColorImageFormat_None;
		if (SUCCEEDED(hr))
		{
			hr = pColorFrame->get_RawColorImageFormat(&imageFormat);
		}
		if (SUCCEEDED(hr))
		{
			if (imageFormat == ColorImageFormat_Bgra)//����������format����֪�����庬�壬���һ��Ԥ�ȷ����ڴ棬һ����Ҫ�Լ����ռ��  
			{
				hr = pColorFrame->AccessRawUnderlyingBuffer(&nBufferSize_color, reinterpret_cast<BYTE**>(&pBuffer_color));
			}
			else if (m_pColorRGBX)
			{
				pBuffer_color = m_pColorRGBX;
				nBufferSize_color = ColorWidth * ColorHeight * sizeof(RGBQUAD);
				hr = pColorFrame->CopyConvertedFrameDataToArray(nBufferSize_color, reinterpret_cast<BYTE*>(pBuffer_color), ColorImageFormat_Bgra);
			}
			else
			{
				hr = E_FAIL;
			}
			colorImg = ConvertMat(pBuffer_color, ColorWidth, ColorHeight);
		}
	}
	SafeRelease(pColorFrame);
	resize(colorImg, NewColorImage, dsize);
	return colorImg;
}


Mat Color::ConvertMat(const RGBQUAD* pBuffer, int nWidth, int nHeight)
{
	Mat img=Mat::zeros(nHeight, nWidth, CV_8UC3);

	uchar* p_mat = img.data;

	const RGBQUAD* pBufferEnd = pBuffer + (nWidth * nHeight);

	while (pBuffer < pBufferEnd)
	{
		//*p_mat = pBuffer->rgbBlue;
		//p_mat++;
		//*p_mat = pBuffer->rgbGreen;
		//p_mat++;
		//*p_mat = pBuffer->rgbRed;
		//p_mat++;

		*p_mat = pBuffer->rgbRed;
		p_mat++;
		*p_mat = pBuffer->rgbGreen;
		p_mat++;
		*p_mat = pBuffer->rgbBlue;
		p_mat++;


		++pBuffer;
	}
	return img;
}


void Color::DrawRec(Mat thresholdImage, Mat &cameraFeed, UINT16 *pixData){
	Mat temp;
	Rect objectBoundingRectangle = Rect(0, 0, 0, 0);
	thresholdImage.copyTo(temp);
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(temp, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE); //Ѱ������
	if (contours.size() > 0){
		vector < vector<Point> > largestContours;
		largestContours.push_back(contours.at(contours.size() - 1));
		objectBoundingRectangle = boundingRect(largestContours.at(0));//�ҵ������С����
		rectangle(cameraFeed, objectBoundingRectangle, Scalar(0, 0, 255), 5, 8, 0);//�����������
		int x = objectBoundingRectangle.x + objectBoundingRectangle.width / 2;
		int y = objectBoundingRectangle.y + objectBoundingRectangle.height / 2;
		circle(cameraFeed, Point(x, y), 5, Scalar(0, 0, 255), 4);
		//putText(cameraFeed, "Tracking object at (" + intToString(x) + "," + intToString(y) + ")", Point(x, y), 1, 1, Scalar(255, 0, 0), 2);
		//INT32 pixelIndex = (INT32)(x + ((INT32)y *512));
		//double depth = (pixData[pixelIndex]>>3);
		//double depth = (pixData[pixelIndex]);
		/*double distance = depth / 10;
		if (depth > 0){
			cout << "(" << x << ", " << y << ", ";
			cout << distance << "cm )" << endl;
		}*/

	}
}