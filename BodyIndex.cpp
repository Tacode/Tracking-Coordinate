#include "BodyIndex.h"

BodyIndex::BodyIndex()
{
	
}


BodyIndex::~BodyIndex()
{
	SafeRelease(pBodyIndexFrameReader);
}

HRESULT BodyIndex::InitBodyIndex(IKinectSensor *kinect){
	pBodyIndexFrameSource = NULL;
	pBodyIndexFrameReader = NULL;
	/*初始化BodyIndex*/
	hr = kinect->get_BodyIndexFrameSource(&pBodyIndexFrameSource);
	if (!SUCCEEDED(hr)){
		cout << "获取Body源失败" << endl;
		return E_FAIL;
	}

	hr = pBodyIndexFrameSource->OpenReader(&pBodyIndexFrameReader);
	if (!SUCCEEDED(hr)){
		cout << "打开读取器失败" << endl;
		return E_FAIL;
	}
	SafeRelease(pBodyIndexFrameSource);
	return S_OK;
}


Mat BodyIndex::updateBodyIndex(Mat &IndexImg){
	hr = S_OK;
	IBodyIndexFrame * pBodyIndexFrame = NULL;
	Mat element = getStructuringElement(MORPH_RECT, Size(5, 5));
	/*BodyIndex图像获取及显示*/
	if (SUCCEEDED(hr)){
		hr = pBodyIndexFrameReader->AcquireLatestFrame(&pBodyIndexFrame);
	}
	if (SUCCEEDED(hr)){
		//BYTE *bodyIndexArray = new BYTE[height* width];//背景二值图是8为uchar，有人是黑色，没人是白色
		//pBodyIndexFrame->CopyFrameDataToArray(height* width, bodyIndexArray);
		//uchar* Data = (uchar*)img.data;
		//for (int j = 0; j < height * width; ++j){
		//	*Data = bodyIndexArray[j]; ++Data;
		//	*Data = bodyIndexArray[j]; ++Data;
		//	*Data = bodyIndexArray[j]; ++Data;
		//}
		//delete[] bodyIndexArray;
		UINT nBufferSize = 0;
		unsigned char* pBuffer = nullptr;
		pBodyIndexFrame->AccessUnderlyingBuffer(&nBufferSize, &pBuffer);

		for (int x = 0; x < height; x++)
		{
			for (int y = 0; y < width; y++)

			{
				unsigned int index = x *width + y;
				if (pBuffer[index] != 255)
				{
					IndexImg.at<Vec3b>(x, y) = Vec3b(0, 255, 0);
				}
				else
				{
					IndexImg.at<Vec3b>(x, y) = Vec3b(0, 0, 0);
				}
			}
		}
	}
	dilate(IndexImg, IndexImg, element);
	erode(IndexImg, IndexImg, element);
	SafeRelease(pBodyIndexFrame);
	cvtColor(IndexImg, thresholdImage, COLOR_BGR2GRAY);
	threshold(thresholdImage, thresholdImage, 25, 255, THRESH_BINARY);
	//searchForMovement(thresholdImage, img);
	//DrawRec(thresholdImage, IndexImg);
	//cvNamedWindow("BodyIndexImage");
	//imshow("BodyIndexImage", IndexImg);
	//if (waitKey(34) == VK_ESCAPE){
	//	cvDestroyAllWindows();
	//	exit(0);
	//}
	return thresholdImage;
}

double * BodyIndex::DrawRec(Mat thresholdImage, Mat &cameraFeed, UINT16 *pixData){
	Mat temp;
	Rect objectBoundingRectangle = Rect(0, 0, 0, 0);
	memset(location, 0, sizeof(double)*3);
	thresholdImage.copyTo(temp);
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(temp, contours, hierarchy, CV_RETR_EXTERNAL, CV_CHAIN_APPROX_SIMPLE); //寻找轮廓
	if (contours.size() > 0){
		vector < vector<Point> > largestContours;
		largestContours.push_back(contours.at(contours.size() - 1));
		objectBoundingRectangle = boundingRect(largestContours.at(0));//找到外接最小轮廓
		rectangle(cameraFeed, objectBoundingRectangle, Scalar(255, 0, 0), 5, 8, 0);//画出外接轮廓
		int x = objectBoundingRectangle.x + objectBoundingRectangle.width / 2;
		int y = objectBoundingRectangle.y + objectBoundingRectangle.height / 2;
		circle(cameraFeed, Point(x, y), 5, Scalar(255, 0, 0), 4);
		//putText(cameraFeed, "Tracking object at (" + intToString(x) + "," + intToString(y) + ")", Point(x, y), 1, 1, Scalar(255, 0, 0), 2);
		INT32 pixelIndex = (INT32)(x + ((INT32)y *width));
		//double depth = (pixData[pixelIndex]>>3);
		double depth = (pixData[pixelIndex]);
		double distance = depth / 10;
	//	count++;
		if (depth > 0){
			/*cout << "(" << x << ", " << y << ", ";
			cout << distance << "cm )" << endl;*/

			location[0] = x;
			location[1] = y;
			location[2] = distance;
		}

	}
	return location;
}