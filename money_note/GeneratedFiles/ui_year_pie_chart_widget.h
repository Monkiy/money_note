/********************************************************************************
** Form generated from reading UI file 'year_pie_chart_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_YEAR_PIE_CHART_WIDGET_H
#define UI_YEAR_PIE_CHART_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_year_pie_chart_widget
{
public:
    QLabel *label;

    void setupUi(QWidget *year_pie_chart_widget)
    {
        if (year_pie_chart_widget->objectName().isEmpty())
            year_pie_chart_widget->setObjectName(QString::fromUtf8("year_pie_chart_widget"));
        year_pie_chart_widget->resize(800, 600);
        label = new QLabel(year_pie_chart_widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(150, 100, 54, 12));

        retranslateUi(year_pie_chart_widget);

        QMetaObject::connectSlotsByName(year_pie_chart_widget);
    } // setupUi

    void retranslateUi(QWidget *year_pie_chart_widget)
    {
        year_pie_chart_widget->setWindowTitle(QCoreApplication::translate("year_pie_chart_widget", "Form", nullptr));
        label->setText(QCoreApplication::translate("year_pie_chart_widget", "year pie", nullptr));
    } // retranslateUi

};

namespace Ui {
    class year_pie_chart_widget: public Ui_year_pie_chart_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_YEAR_PIE_CHART_WIDGET_H
