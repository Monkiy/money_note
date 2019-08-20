/********************************************************************************
** Form generated from reading UI file 'add_note_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADD_NOTE_WIDGET_H
#define UI_ADD_NOTE_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_add_note_widget
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_type;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_add_note;
    QPushButton *pushButton_add_type;
    QDoubleSpinBox *doubleSpinBox_value;
    QLineEdit *lineEdit_note;
    QComboBox *comboBox_type;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QGroupBox *groupBox_day;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget_day;

    void setupUi(QWidget *add_note_widget)
    {
        if (add_note_widget->objectName().isEmpty())
            add_note_widget->setObjectName(QString::fromUtf8("add_note_widget"));
        add_note_widget->resize(800, 600);
        verticalLayout = new QVBoxLayout(add_note_widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        lineEdit_type = new QLineEdit(add_note_widget);
        lineEdit_type->setObjectName(QString::fromUtf8("lineEdit_type"));
        lineEdit_type->setMinimumSize(QSize(160, 0));
        lineEdit_type->setMaximumSize(QSize(160, 16777215));

        gridLayout->addWidget(lineEdit_type, 0, 5, 1, 1);

        label = new QLabel(add_note_widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 3, 1, 1);

        pushButton_add_note = new QPushButton(add_note_widget);
        pushButton_add_note->setObjectName(QString::fromUtf8("pushButton_add_note"));

        gridLayout->addWidget(pushButton_add_note, 0, 2, 1, 1);

        pushButton_add_type = new QPushButton(add_note_widget);
        pushButton_add_type->setObjectName(QString::fromUtf8("pushButton_add_type"));

        gridLayout->addWidget(pushButton_add_type, 0, 6, 1, 1);

        doubleSpinBox_value = new QDoubleSpinBox(add_note_widget);
        doubleSpinBox_value->setObjectName(QString::fromUtf8("doubleSpinBox_value"));
        doubleSpinBox_value->setMaximum(9999.989999999999782);

        gridLayout->addWidget(doubleSpinBox_value, 1, 1, 1, 1);

        lineEdit_note = new QLineEdit(add_note_widget);
        lineEdit_note->setObjectName(QString::fromUtf8("lineEdit_note"));
        lineEdit_note->setMinimumSize(QSize(200, 0));
        lineEdit_note->setMaximumSize(QSize(200, 16777215));

        gridLayout->addWidget(lineEdit_note, 2, 1, 1, 1);

        comboBox_type = new QComboBox(add_note_widget);
        comboBox_type->setObjectName(QString::fromUtf8("comboBox_type"));

        gridLayout->addWidget(comboBox_type, 0, 1, 1, 1);

        label_2 = new QLabel(add_note_widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_3 = new QLabel(add_note_widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        label_4 = new QLabel(add_note_widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);

        groupBox_day = new QGroupBox(add_note_widget);
        groupBox_day->setObjectName(QString::fromUtf8("groupBox_day"));
        verticalLayout_2 = new QVBoxLayout(groupBox_day);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        tableWidget_day = new QTableWidget(groupBox_day);
        if (tableWidget_day->columnCount() < 3)
            tableWidget_day->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_day->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_day->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_day->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        tableWidget_day->setObjectName(QString::fromUtf8("tableWidget_day"));

        verticalLayout_2->addWidget(tableWidget_day);


        verticalLayout->addWidget(groupBox_day);

        verticalLayout->setStretch(1, 1);

        retranslateUi(add_note_widget);
        QObject::connect(pushButton_add_note, SIGNAL(clicked()), add_note_widget, SLOT(slot_add_note_bt_clicked()));
        QObject::connect(pushButton_add_type, SIGNAL(clicked()), add_note_widget, SLOT(slot_add_type_bt_clicked()));

        QMetaObject::connectSlotsByName(add_note_widget);
    } // setupUi

    void retranslateUi(QWidget *add_note_widget)
    {
        add_note_widget->setWindowTitle(QCoreApplication::translate("add_note_widget", "Form", nullptr));
        label->setText(QCoreApplication::translate("add_note_widget", "\347\261\273\345\210\253", nullptr));
        pushButton_add_note->setText(QCoreApplication::translate("add_note_widget", "\346\226\260\345\242\236", nullptr));
        pushButton_add_type->setText(QCoreApplication::translate("add_note_widget", "\346\226\260\345\242\236", nullptr));
        label_2->setText(QCoreApplication::translate("add_note_widget", "\351\207\221\351\242\235", nullptr));
        label_3->setText(QCoreApplication::translate("add_note_widget", "\346\217\217\350\277\260", nullptr));
        label_4->setText(QCoreApplication::translate("add_note_widget", "\347\261\273\345\210\253", nullptr));
        groupBox_day->setTitle(QCoreApplication::translate("add_note_widget", "\344\273\212\346\227\245\346\266\210\350\264\271 0", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_day->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("add_note_widget", "\347\261\273\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_day->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("add_note_widget", "\351\207\221\351\242\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_day->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("add_note_widget", "\346\217\217\350\277\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class add_note_widget: public Ui_add_note_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADD_NOTE_WIDGET_H
