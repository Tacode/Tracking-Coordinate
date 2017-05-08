/********************************************************************************
** Form generated from reading UI file 'kinectcoordinate.ui'
**
** Created by: Qt User Interface Compiler version 5.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KINECTCOORDINATE_H
#define UI_KINECTCOORDINATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KinectCoordinateClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *D_X;
    QLabel *label_9;
    QLabel *label_10;
    QLineEdit *D_Y;
    QLineEdit *D_Z;
    QLineEdit *W_Z;
    QLineEdit *W_Y;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *W_X;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *KinectCoordinateClass)
    {
        if (KinectCoordinateClass->objectName().isEmpty())
            KinectCoordinateClass->setObjectName(QStringLiteral("KinectCoordinateClass"));
        KinectCoordinateClass->resize(896, 618);
        KinectCoordinateClass->setMinimumSize(QSize(896, 618));
        KinectCoordinateClass->setMaximumSize(QSize(896, 618));
        centralWidget = new QWidget(KinectCoordinateClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 10, 271, 221));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(440, 10, 271, 221));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 300, 271, 221));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(440, 300, 271, 221));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(160, 260, 54, 12));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(560, 260, 54, 12));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(160, 540, 54, 12));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(770, 60, 21, 21));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_8->setFont(font);
        D_X = new QLineEdit(centralWidget);
        D_X->setObjectName(QStringLiteral("D_X"));
        D_X->setGeometry(QRect(800, 60, 61, 20));
        D_X->setCursor(QCursor(Qt::BlankCursor));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(770, 100, 21, 21));
        label_9->setFont(font);
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(770, 140, 21, 21));
        label_10->setFont(font);
        D_Y = new QLineEdit(centralWidget);
        D_Y->setObjectName(QStringLiteral("D_Y"));
        D_Y->setGeometry(QRect(800, 100, 61, 20));
        D_Y->setCursor(QCursor(Qt::BlankCursor));
        D_Z = new QLineEdit(centralWidget);
        D_Z->setObjectName(QStringLiteral("D_Z"));
        D_Z->setGeometry(QRect(800, 140, 61, 20));
        D_Z->setCursor(QCursor(Qt::BlankCursor));
        W_Z = new QLineEdit(centralWidget);
        W_Z->setObjectName(QStringLiteral("W_Z"));
        W_Z->setGeometry(QRect(800, 480, 61, 20));
        W_Z->setCursor(QCursor(Qt::BlankCursor));
        W_Y = new QLineEdit(centralWidget);
        W_Y->setObjectName(QStringLiteral("W_Y"));
        W_Y->setGeometry(QRect(800, 440, 61, 20));
        W_Y->setCursor(QCursor(Qt::BlankCursor));
        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(770, 480, 21, 21));
        label_11->setFont(font);
        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(770, 400, 21, 21));
        label_12->setFont(font);
        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(770, 440, 21, 21));
        label_13->setFont(font);
        W_X = new QLineEdit(centralWidget);
        W_X->setObjectName(QStringLiteral("W_X"));
        W_X->setGeometry(QRect(800, 400, 61, 20));
        W_X->setCursor(QCursor(Qt::BlankCursor));
        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(780, 30, 71, 20));
        label_14->setFont(font);
        label_15 = new QLabel(centralWidget);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(780, 370, 71, 20));
        label_15->setFont(font);
        label_16 = new QLabel(centralWidget);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(870, 140, 21, 21));
        label_16->setFont(font);
        label_17 = new QLabel(centralWidget);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(870, 400, 21, 21));
        label_17->setFont(font);
        label_18 = new QLabel(centralWidget);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(870, 440, 21, 21));
        label_18->setFont(font);
        label_19 = new QLabel(centralWidget);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(870, 480, 21, 21));
        label_19->setFont(font);
        label_20 = new QLabel(centralWidget);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(870, 100, 21, 21));
        label_20->setFont(font);
        label_21 = new QLabel(centralWidget);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(870, 60, 21, 21));
        label_21->setFont(font);
        KinectCoordinateClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(KinectCoordinateClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 896, 23));
        KinectCoordinateClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(KinectCoordinateClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        KinectCoordinateClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(KinectCoordinateClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        KinectCoordinateClass->setStatusBar(statusBar);

        retranslateUi(KinectCoordinateClass);

        QMetaObject::connectSlotsByName(KinectCoordinateClass);
    } // setupUi

    void retranslateUi(QMainWindow *KinectCoordinateClass)
    {
        KinectCoordinateClass->setWindowTitle(QApplication::translate("KinectCoordinateClass", "KinectCoordinate", 0));
        label->setText(QApplication::translate("KinectCoordinateClass", "TextLabel", 0));
        label_2->setText(QApplication::translate("KinectCoordinateClass", "TextLabel", 0));
        label_3->setText(QApplication::translate("KinectCoordinateClass", "TextLabel", 0));
        label_4->setText(QApplication::translate("KinectCoordinateClass", "TextLabel", 0));
        label_5->setText(QApplication::translate("KinectCoordinateClass", "\346\267\261\345\272\246\345\233\276", 0));
        label_6->setText(QApplication::translate("KinectCoordinateClass", "\350\275\256\345\273\223\345\233\276", 0));
        label_7->setText(QApplication::translate("KinectCoordinateClass", "\345\275\251\350\211\262\345\233\276", 0));
        label_8->setText(QApplication::translate("KinectCoordinateClass", "X\357\274\232", 0));
        label_9->setText(QApplication::translate("KinectCoordinateClass", "Y\357\274\232", 0));
        label_10->setText(QApplication::translate("KinectCoordinateClass", "Z\357\274\232", 0));
        label_11->setText(QApplication::translate("KinectCoordinateClass", "Z\357\274\232", 0));
        label_12->setText(QApplication::translate("KinectCoordinateClass", "X\357\274\232", 0));
        label_13->setText(QApplication::translate("KinectCoordinateClass", "Y\357\274\232", 0));
        label_14->setText(QApplication::translate("KinectCoordinateClass", "\346\267\261\345\272\246\345\235\220\346\240\207\347\263\273", 0));
        label_15->setText(QApplication::translate("KinectCoordinateClass", "\344\270\226\347\225\214\345\235\220\346\240\207\347\263\273", 0));
        label_16->setText(QApplication::translate("KinectCoordinateClass", "Cm", 0));
        label_17->setText(QApplication::translate("KinectCoordinateClass", "Cm", 0));
        label_18->setText(QApplication::translate("KinectCoordinateClass", "Cm", 0));
        label_19->setText(QApplication::translate("KinectCoordinateClass", "Cm", 0));
        label_20->setText(QApplication::translate("KinectCoordinateClass", "Px", 0));
        label_21->setText(QApplication::translate("KinectCoordinateClass", "Px", 0));
    } // retranslateUi

};

namespace Ui {
    class KinectCoordinateClass: public Ui_KinectCoordinateClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KINECTCOORDINATE_H
