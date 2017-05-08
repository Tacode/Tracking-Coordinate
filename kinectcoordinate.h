#ifndef KINECTCOORDINATE_H
#define KINECTCOORDINATE_H

#include <QtWidgets/QMainWindow>
#include "ui_kinectcoordinate.h"
#include <opencv2\highgui\highgui.hpp>
#include <cv.h>
#include <Kinect.h>
#include <qdebug.h>
#include <qtimer.h>
#include <math.h>
#include "Depth.h"
#include "BodyIndex.h"
#include "Color.h"



class KinectCoordinate : public QMainWindow
{
	Q_OBJECT

public:
	KinectCoordinate(QWidget *parent = 0);
	~KinectCoordinate();
	HRESULT hr;
	Depth * myDepth;
	BodyIndex *myBodyIndex;
	Color *myColorImg;
	QTimer *timer;
	void showImage(Mat tmpImg,QLabel *qLabel);
	IKinectSensor * Kinect;
	HRESULT init();
	inline double D2R(double deg);
public slots:
	void slot1();
private:
	Ui::KinectCoordinateClass ui;
	cv::Mat img = cv::Mat::zeros(424, 512, CV_8UC3);
	Mat thresholdImg = Mat::zeros(424, 512, CV_8UC3);
	Mat BodyIndexImg = Mat::zeros(424, 512, CV_8UC3);
	Mat ColorImg = Mat::zeros(424, 512, CV_8UC3);
	double *location = new double[3];
	double *wlocation = new double[3];
	int count=0;
	UINT16 *pixData;

};

#endif // KINECTCOORDINATE_H
