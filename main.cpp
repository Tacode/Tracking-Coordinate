#include "kinectcoordinate.h"
#include <QtWidgets/QApplication>
#include <qsplashscreen.h>
#include <qelapsedtimer.h>
#include <qtextcodec.h>
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	QSplashScreen *splash = new QSplashScreen;
	splash->setPixmap(QPixmap("E:\\KinectCode\\Coordination\\KinectCoordinate\\KinectCoordinate\\Kinectf.jpg"));
	splash->setDisabled(true);
	Qt::Alignment BottomRight = Qt::AlignBottom | Qt::AlignRight;
	splash->showMessage("Setting up the main window......", BottomRight,Qt::white);
	splash->show();

	QElapsedTimer t;
	t.start();
	while (t.elapsed()<1500)
	{
		QCoreApplication::processEvents();
	}


	KinectCoordinate w;
	w.show();
	splash->finish(&w);
	delete splash;
	return a.exec();
}
