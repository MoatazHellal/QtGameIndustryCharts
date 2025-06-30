/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *BarsTab;
    QWidget *HorizontalStackedBarsTab;
    QWidget *LineTab;
    QWidget *PieTab;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(4, 9, 791, 561));
        BarsTab = new QWidget();
        BarsTab->setObjectName("BarsTab");
        tabWidget->addTab(BarsTab, QString());
        HorizontalStackedBarsTab = new QWidget();
        HorizontalStackedBarsTab->setObjectName("HorizontalStackedBarsTab");
        tabWidget->addTab(HorizontalStackedBarsTab, QString());
        LineTab = new QWidget();
        LineTab->setObjectName("LineTab");
        tabWidget->addTab(LineTab, QString());
        PieTab = new QWidget();
        PieTab->setObjectName("PieTab");
        tabWidget->addTab(PieTab, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(BarsTab), QCoreApplication::translate("MainWindow", "Bars Chart", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(HorizontalStackedBarsTab), QCoreApplication::translate("MainWindow", "H-Bars Chart", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(LineTab), QCoreApplication::translate("MainWindow", "Line Chart", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(PieTab), QCoreApplication::translate("MainWindow", "Pie Chart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
