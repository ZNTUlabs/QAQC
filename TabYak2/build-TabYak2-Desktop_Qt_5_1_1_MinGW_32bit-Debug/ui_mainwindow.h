/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *openfile;
    QPushButton *Metrics;
    QLabel *label_NOC;
    QLabel *label_MWC;
    QLabel *label_SrKMet;
    QLabel *label_SrKSCl;
    QLabel *label_RFC;
    QLabel *label_NORM;
    QLabel *label_Met;
    QLabel *label_Class;
    QPlainTextEdit *plainTextEdit;
    QLabel *Kol_Class;
    QLabel *Include;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(620, 261);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        openfile = new QPushButton(centralWidget);
        openfile->setObjectName(QStringLiteral("openfile"));
        openfile->setGeometry(QRect(540, 180, 75, 23));
        Metrics = new QPushButton(centralWidget);
        Metrics->setObjectName(QStringLiteral("Metrics"));
        Metrics->setGeometry(QRect(420, 180, 75, 23));
        label_NOC = new QLabel(centralWidget);
        label_NOC->setObjectName(QStringLiteral("label_NOC"));
        label_NOC->setGeometry(QRect(20, 40, 61, 16));
        label_MWC = new QLabel(centralWidget);
        label_MWC->setObjectName(QStringLiteral("label_MWC"));
        label_MWC->setGeometry(QRect(100, 40, 71, 16));
        label_SrKMet = new QLabel(centralWidget);
        label_SrKMet->setObjectName(QStringLiteral("label_SrKMet"));
        label_SrKMet->setGeometry(QRect(190, 40, 81, 16));
        label_SrKSCl = new QLabel(centralWidget);
        label_SrKSCl->setObjectName(QStringLiteral("label_SrKSCl"));
        label_SrKSCl->setGeometry(QRect(320, 40, 81, 16));
        label_RFC = new QLabel(centralWidget);
        label_RFC->setObjectName(QStringLiteral("label_RFC"));
        label_RFC->setGeometry(QRect(20, 120, 71, 16));
        label_NORM = new QLabel(centralWidget);
        label_NORM->setObjectName(QStringLiteral("label_NORM"));
        label_NORM->setGeometry(QRect(100, 120, 71, 16));
        label_Met = new QLabel(centralWidget);
        label_Met->setObjectName(QStringLiteral("label_Met"));
        label_Met->setGeometry(QRect(200, 120, 61, 16));
        label_Class = new QLabel(centralWidget);
        label_Class->setObjectName(QStringLiteral("label_Class"));
        label_Class->setGeometry(QRect(320, 120, 61, 16));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(390, 10, 221, 151));
        Kol_Class = new QLabel(centralWidget);
        Kol_Class->setObjectName(QStringLiteral("Kol_Class"));
        Kol_Class->setGeometry(QRect(40, 190, 61, 16));
        Include = new QLabel(centralWidget);
        Include->setObjectName(QStringLiteral("Include"));
        Include->setGeometry(QRect(280, 190, 46, 13));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 10, 61, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(100, 10, 61, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(190, 10, 71, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(320, 10, 61, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 100, 51, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(100, 100, 71, 20));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(200, 100, 51, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(320, 100, 61, 16));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(40, 170, 46, 13));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(280, 170, 46, 13));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 620, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        openfile->setText(QApplication::translate("MainWindow", "openfile", 0));
        Metrics->setText(QApplication::translate("MainWindow", "Metrics", 0));
        label_NOC->setText(QApplication::translate("MainWindow", "label_NOC", 0));
        label_MWC->setText(QApplication::translate("MainWindow", "Label_MWC", 0));
        label_SrKMet->setText(QApplication::translate("MainWindow", "label_SrKMet", 0));
        label_SrKSCl->setText(QApplication::translate("MainWindow", "label_SrKSCl", 0));
        label_RFC->setText(QApplication::translate("MainWindow", "label_RFC", 0));
        label_NORM->setText(QApplication::translate("MainWindow", "label_NORM", 0));
        label_Met->setText(QApplication::translate("MainWindow", "label_Met", 0));
        label_Class->setText(QApplication::translate("MainWindow", "label_Class", 0));
        Kol_Class->setText(QApplication::translate("MainWindow", "Kol_Class", 0));
        Include->setText(QApplication::translate("MainWindow", "Include", 0));
        label->setText(QApplication::translate("MainWindow", "NOC", 0));
        label_2->setText(QApplication::translate("MainWindow", "MWC", 0));
        label_3->setText(QApplication::translate("MainWindow", "SrKMet", 0));
        label_4->setText(QApplication::translate("MainWindow", "SrKSCl", 0));
        label_5->setText(QApplication::translate("MainWindow", "RFC", 0));
        label_6->setText(QApplication::translate("MainWindow", "NORM", 0));
        label_7->setText(QApplication::translate("MainWindow", "Met", 0));
        label_8->setText(QApplication::translate("MainWindow", "Class", 0));
        label_9->setText(QApplication::translate("MainWindow", "Kol_Class", 0));
        label_10->setText(QApplication::translate("MainWindow", "Include", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
