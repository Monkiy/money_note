/********************************************************************************
** Form generated from reading UI file 'money_note_widget.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONEY_NOTE_WIDGET_H
#define UI_MONEY_NOTE_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_money_note_widget
{
public:
    QHBoxLayout *horizontalLayout_5;
    QGroupBox *groupBox_year;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QDateEdit *dateEdit_year;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_year_chart;
    QPushButton *pushButton_month_chart;
    QPushButton *pushButton_year_pie_chart;
    QHBoxLayout *horizontalLayout_3;
    QTableWidget *tableWidget_year;
    QTableWidget *tableWidget_year_class;
    QGroupBox *groupBox_month;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_month_pie_chart;
    QTableWidget *tableWidget_month_class;
    QGroupBox *groupBox_day;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_add;
    QTableWidget *tableWidget_day;

    void setupUi(QWidget *money_note_widget)
    {
        if (money_note_widget->objectName().isEmpty())
            money_note_widget->setObjectName(QString::fromUtf8("money_note_widget"));
        money_note_widget->resize(800, 600);
        horizontalLayout_5 = new QHBoxLayout(money_note_widget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        groupBox_year = new QGroupBox(money_note_widget);
        groupBox_year->setObjectName(QString::fromUtf8("groupBox_year"));
        verticalLayout = new QVBoxLayout(groupBox_year);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        dateEdit_year = new QDateEdit(groupBox_year);
        dateEdit_year->setObjectName(QString::fromUtf8("dateEdit_year"));

        horizontalLayout->addWidget(dateEdit_year);

        label = new QLabel(groupBox_year);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_year_chart = new QPushButton(groupBox_year);
        pushButton_year_chart->setObjectName(QString::fromUtf8("pushButton_year_chart"));

        horizontalLayout->addWidget(pushButton_year_chart);

        pushButton_month_chart = new QPushButton(groupBox_year);
        pushButton_month_chart->setObjectName(QString::fromUtf8("pushButton_month_chart"));

        horizontalLayout->addWidget(pushButton_month_chart);

        pushButton_year_pie_chart = new QPushButton(groupBox_year);
        pushButton_year_pie_chart->setObjectName(QString::fromUtf8("pushButton_year_pie_chart"));

        horizontalLayout->addWidget(pushButton_year_pie_chart);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tableWidget_year = new QTableWidget(groupBox_year);
        if (tableWidget_year->columnCount() < 2)
            tableWidget_year->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget_year->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget_year->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget_year->setObjectName(QString::fromUtf8("tableWidget_year"));

        horizontalLayout_3->addWidget(tableWidget_year);

        tableWidget_year_class = new QTableWidget(groupBox_year);
        if (tableWidget_year_class->columnCount() < 3)
            tableWidget_year_class->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget_year_class->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget_year_class->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget_year_class->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        tableWidget_year_class->setObjectName(QString::fromUtf8("tableWidget_year_class"));

        horizontalLayout_3->addWidget(tableWidget_year_class);


        verticalLayout->addLayout(horizontalLayout_3);


        horizontalLayout_5->addWidget(groupBox_year);

        groupBox_month = new QGroupBox(money_note_widget);
        groupBox_month->setObjectName(QString::fromUtf8("groupBox_month"));
        verticalLayout_2 = new QVBoxLayout(groupBox_month);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pushButton_month_pie_chart = new QPushButton(groupBox_month);
        pushButton_month_pie_chart->setObjectName(QString::fromUtf8("pushButton_month_pie_chart"));

        horizontalLayout_4->addWidget(pushButton_month_pie_chart);


        verticalLayout_2->addLayout(horizontalLayout_4);

        tableWidget_month_class = new QTableWidget(groupBox_month);
        if (tableWidget_month_class->columnCount() < 3)
            tableWidget_month_class->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget_month_class->setHorizontalHeaderItem(0, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget_month_class->setHorizontalHeaderItem(1, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget_month_class->setHorizontalHeaderItem(2, __qtablewidgetitem7);
        tableWidget_month_class->setObjectName(QString::fromUtf8("tableWidget_month_class"));

        verticalLayout_2->addWidget(tableWidget_month_class);


        horizontalLayout_5->addWidget(groupBox_month);

        groupBox_day = new QGroupBox(money_note_widget);
        groupBox_day->setObjectName(QString::fromUtf8("groupBox_day"));
        verticalLayout_3 = new QVBoxLayout(groupBox_day);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButton_add = new QPushButton(groupBox_day);
        pushButton_add->setObjectName(QString::fromUtf8("pushButton_add"));

        horizontalLayout_2->addWidget(pushButton_add);


        verticalLayout_3->addLayout(horizontalLayout_2);

        tableWidget_day = new QTableWidget(groupBox_day);
        if (tableWidget_day->columnCount() < 3)
            tableWidget_day->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget_day->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget_day->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget_day->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        tableWidget_day->setObjectName(QString::fromUtf8("tableWidget_day"));

        verticalLayout_3->addWidget(tableWidget_day);


        horizontalLayout_5->addWidget(groupBox_day);

        horizontalLayout_5->setStretch(0, 2);
        horizontalLayout_5->setStretch(1, 1);
        horizontalLayout_5->setStretch(2, 1);

        retranslateUi(money_note_widget);
        QObject::connect(pushButton_add, SIGNAL(clicked()), money_note_widget, SLOT(slot_add_note_bt_clicked()));
        QObject::connect(pushButton_month_pie_chart, SIGNAL(clicked()), money_note_widget, SLOT(slot_month_pie_chart_bt_clicked()));
        QObject::connect(pushButton_month_chart, SIGNAL(clicked()), money_note_widget, SLOT(slot_month_line_chart_bt_clicked()));
        QObject::connect(pushButton_year_chart, SIGNAL(clicked()), money_note_widget, SLOT(slot_year_line_chart_bt_clicked()));
        QObject::connect(pushButton_year_pie_chart, SIGNAL(clicked()), money_note_widget, SLOT(slot_year_pie_chart_bt_clicked()));

        QMetaObject::connectSlotsByName(money_note_widget);
    } // setupUi

    void retranslateUi(QWidget *money_note_widget)
    {
        money_note_widget->setWindowTitle(QCoreApplication::translate("money_note_widget", "Form", nullptr));
        groupBox_year->setTitle(QCoreApplication::translate("money_note_widget", "\345\271\264\345\272\246\346\200\273\350\256\241 0", nullptr));
        dateEdit_year->setDisplayFormat(QCoreApplication::translate("money_note_widget", "yyyy", nullptr));
        label->setText(QCoreApplication::translate("money_note_widget", "\345\271\264", nullptr));
        pushButton_year_chart->setText(QCoreApplication::translate("money_note_widget", "\345\216\206\345\271\264\346\212\230\347\272\277\345\233\276", nullptr));
        pushButton_month_chart->setText(QCoreApplication::translate("money_note_widget", "\345\271\264\345\272\246\346\212\230\347\272\277\345\233\276", nullptr));
        pushButton_year_pie_chart->setText(QCoreApplication::translate("money_note_widget", "\346\211\207\345\275\242\345\233\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget_year->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("money_note_widget", "\346\234\210\344\273\275", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget_year->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("money_note_widget", "\351\207\221\351\242\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget_year_class->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("money_note_widget", "\347\261\273\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget_year_class->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("money_note_widget", "\351\207\221\351\242\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget_year_class->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("money_note_widget", "\346\257\224\344\276\213", nullptr));
        groupBox_month->setTitle(QCoreApplication::translate("money_note_widget", "\346\234\254\346\234\210\346\200\273\350\256\241 0", nullptr));
        pushButton_month_pie_chart->setText(QCoreApplication::translate("money_note_widget", "\346\211\207\345\275\242\345\233\276", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget_month_class->horizontalHeaderItem(0);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("money_note_widget", "\347\261\273\345\210\253", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget_month_class->horizontalHeaderItem(1);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("money_note_widget", "\351\207\221\351\242\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget_month_class->horizontalHeaderItem(2);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("money_note_widget", "\346\257\224\344\276\213", nullptr));
        groupBox_day->setTitle(QCoreApplication::translate("money_note_widget", "\344\273\212\346\227\245\346\200\273\350\256\241 0", nullptr));
        pushButton_add->setText(QCoreApplication::translate("money_note_widget", "\346\226\260\345\242\236", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget_day->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("money_note_widget", "\347\261\273\345\236\213", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget_day->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("money_note_widget", "\351\207\221\351\242\235", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget_day->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("money_note_widget", "\346\217\217\350\277\260", nullptr));
    } // retranslateUi

};

namespace Ui {
    class money_note_widget: public Ui_money_note_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONEY_NOTE_WIDGET_H
