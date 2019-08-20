/********************************************************************************
** Form generated from reading UI file 'month_pie_chart_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONTH_PIE_CHART_WIDGET_H
#define UI_MONTH_PIE_CHART_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_month_pie_chart_widget
{
public:
    QLabel *label;

    void setupUi(QWidget *month_pie_chart_widget)
    {
        if (month_pie_chart_widget->objectName().isEmpty())
            month_pie_chart_widget->setObjectName(QString::fromUtf8("month_pie_chart_widget"));
        month_pie_chart_widget->resize(800, 600);
        label = new QLabel(month_pie_chart_widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(230, 210, 54, 12));

        retranslateUi(month_pie_chart_widget);

        QMetaObject::connectSlotsByName(month_pie_chart_widget);
    } // setupUi

    void retranslateUi(QWidget *month_pie_chart_widget)
    {
        month_pie_chart_widget->setWindowTitle(QCoreApplication::translate("month_pie_chart_widget", "Form", nullptr));
        label->setText(QCoreApplication::translate("month_pie_chart_widget", "month_pie_chart_widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class month_pie_chart_widget: public Ui_month_pie_chart_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONTH_PIE_CHART_WIDGET_H
