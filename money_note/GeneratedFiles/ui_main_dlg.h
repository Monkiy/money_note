/********************************************************************************
** Form generated from reading UI file 'main_dlg.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAIN_DLG_H
#define UI_MAIN_DLG_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_main_dlgClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_home;
    QPushButton *pushButton_upper;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_main;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *main_dlgClass)
    {
        if (main_dlgClass->objectName().isEmpty())
            main_dlgClass->setObjectName(QString::fromUtf8("main_dlgClass"));
        main_dlgClass->resize(800, 600);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/main_dlg/Resources/icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        main_dlgClass->setWindowIcon(icon);
        centralWidget = new QWidget(main_dlgClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_home = new QPushButton(centralWidget);
        pushButton_home->setObjectName(QString::fromUtf8("pushButton_home"));

        horizontalLayout->addWidget(pushButton_home);

        pushButton_upper = new QPushButton(centralWidget);
        pushButton_upper->setObjectName(QString::fromUtf8("pushButton_upper"));

        horizontalLayout->addWidget(pushButton_upper);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_main = new QVBoxLayout();
        verticalLayout_main->setSpacing(6);
        verticalLayout_main->setObjectName(QString::fromUtf8("verticalLayout_main"));

        verticalLayout_2->addLayout(verticalLayout_main);


        verticalLayout->addWidget(groupBox);

        verticalLayout->setStretch(1, 1);
        main_dlgClass->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(main_dlgClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        main_dlgClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(main_dlgClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        main_dlgClass->setStatusBar(statusBar);

        retranslateUi(main_dlgClass);
        QObject::connect(pushButton_home, SIGNAL(clicked()), main_dlgClass, SLOT(slot_home_bt_clicked()));
        QObject::connect(pushButton_upper, SIGNAL(clicked()), main_dlgClass, SLOT(slot_upper_bt_clicked()));

        QMetaObject::connectSlotsByName(main_dlgClass);
    } // setupUi

    void retranslateUi(QMainWindow *main_dlgClass)
    {
        main_dlgClass->setWindowTitle(QCoreApplication::translate("main_dlgClass", "\350\256\260\350\264\246\346\234\254", nullptr));
        pushButton_home->setText(QCoreApplication::translate("main_dlgClass", "\351\246\226\351\241\265", nullptr));
        pushButton_upper->setText(QCoreApplication::translate("main_dlgClass", "\350\277\224\345\233\236\344\270\212\344\270\200\347\272\247", nullptr));
        groupBox->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class main_dlgClass: public Ui_main_dlgClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAIN_DLG_H
