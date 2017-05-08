#include "kinectcoordinate.h"

KinectCoordinate::KinectCoordinate(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	init();
	hr=myDepth->InitKinect(Kinect);
	hr= myBodyIndex->InitBodyIndex(Kinect);
	hr = myColorImg->InitColor(Kinect);
	connect(timer, SIGNAL(timeout()), this, SLOT(slot1()));
	timer->start(10);
}

KinectCoordinate::~KinectCoordinate()
{
	if (Kinect){
		Kinect->Close();
	}
	SafeRelease(Kinect);
}

HRESULT KinectCoordinate::init(){
	Kinect = NULL;
	hr = GetDefaultKinectSensor(&Kinect);
	if (FAILED(hr))
	{
		qDebug() << "Can not find the Kinect!" << endl;
		return E_FAIL;
		exit(0);
	}
	hr = Kinect->Open();
	if (FAILED(hr)){
		qDebug() << "Can not open the Kinect!" << endl;
		return E_FAIL;
		exit(0);
	}
	pixData = new UINT16[424 * 512];
	timer = new QTimer(this);
	myDepth = new Depth();
	myBodyIndex = new BodyIndex();
	myColorImg = new Color();

	ui.D_X->setText(QString::number(0));
	ui.D_Y->setText(QString::number(0));
	ui.D_Z->setText(QString::number(0));
	ui.W_X->setText(QString::number(0));
	ui.W_Y->setText(QString::number(0));
	ui.W_Z->setText(QString::number(0));
	return S_OK;
}


void KinectCoordinate::slot1(){
	pixData = myDepth->updateDepth(img);
	thresholdImg = myBodyIndex->updateBodyIndex(BodyIndexImg);
	myColorImg->updateColorImg(ColorImg);
	location = myBodyIndex->DrawRec(thresholdImg, BodyIndexImg, pixData);
	myColorImg->DrawRec(thresholdImg, ColorImg, pixData);
	showImage(img, ui.label);
	showImage(BodyIndexImg, ui.label_2);
	showImage(ColorImg, ui.label_3);
	//cout << location[0]<<","<<location[1]<<","<<location[2]<<endl;
	wlocation[2] = location[2];
	wlocation[0] = 2 * tan(D2R(35.0))*(location[0]-256) * location[2] / 512;
	wlocation[1] = 2 * tan(D2R(30.0))*(212-location[1]) * location[2] / 424;
	if (location[0] != 0 && location[1] != 0 && location[2] != 0){
		ui.D_X->setText(QString::number(location[0]));
		ui.D_Y->setText(QString::number(location[1]));
		ui.D_Z->setText(QString::number(location[2]));
		ui.W_X->setText(QString::number(wlocation[0],'f',1));
		ui.W_Y->setText(QString::number(wlocation[1], 'f', 1));
		ui.W_Z->setText(QString::number(wlocation[2], 'f', 1));
	}

}

void KinectCoordinate::showImage(Mat tmpImg, QLabel * qLabel){
	QImage image2 = QImage((uchar*)(tmpImg.data), tmpImg.cols, tmpImg.rows, QImage::Format_RGB888);
	qLabel->setPixmap(QPixmap::fromImage(image2));
	//qLabel->resize(image2.size());
	qLabel->setScaledContents(true);
	qLabel->show();
}

inline double KinectCoordinate::D2R(double deg){
	return deg / 180.0 * 3.14159265;
}