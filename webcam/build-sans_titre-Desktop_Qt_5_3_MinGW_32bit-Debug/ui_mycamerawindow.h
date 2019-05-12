/********************************************************************************
** Form generated from reading UI file 'mycamerawindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MYCAMERAWINDOW_H
#define UI_MYCAMERAWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MyCameraWindow
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MyCameraWindow)
    {
        if (MyCameraWindow->objectName().isEmpty())
            MyCameraWindow->setObjectName(QStringLiteral("MyCameraWindow"));
        MyCameraWindow->resize(400, 300);
        menuBar = new QMenuBar(MyCameraWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        MyCameraWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MyCameraWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MyCameraWindow->addToolBar(mainToolBar);
        centralWidget = new QWidget(MyCameraWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MyCameraWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MyCameraWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MyCameraWindow->setStatusBar(statusBar);

        retranslateUi(MyCameraWindow);

        QMetaObject::connectSlotsByName(MyCameraWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MyCameraWindow)
    {
        MyCameraWindow->setWindowTitle(QApplication::translate("MyCameraWindow", "MyCameraWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class MyCameraWindow: public Ui_MyCameraWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MYCAMERAWINDOW_H
