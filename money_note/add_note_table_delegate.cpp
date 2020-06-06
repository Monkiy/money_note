#include "add_note_table_delegate.h"
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QLineEdit>
#include <assert.h>

add_note_table_delegate::add_note_table_delegate(QObject *parent):
    QItemDelegate(parent)
{

}

QWidget * add_note_table_delegate::createEditor(QWidget * parent, const QStyleOptionViewItem & option, const QModelIndex & index) const
{
    assert(3 > index.column());
    if (0 == index.column())
    {
        QComboBox* w = new QComboBox(parent);
        w->addItems(__note_types);
        return w;
    }
    else if (1 == index.column())
    {
        QDoubleSpinBox* w = new QDoubleSpinBox(parent);
        w->setRange(0, 10000);
        return w;
    }
    else if (2 == index.column())
    {
        QLineEdit* w = new QLineEdit(parent);
        return w;
    }
    return nullptr;
}

void add_note_table_delegate::setEditorData(QWidget * editor, const QModelIndex & index) const
{
    assert(3 > index.column());
    if (0 == index.column())
    {
        QComboBox* w = dynamic_cast<QComboBox*>(editor);
        if (!w)
            return;
        w->setCurrentText(index.model()->data(index,Qt::EditRole).toString());
    }
    else if (1 == index.column())
    {
        QDoubleSpinBox* w = dynamic_cast<QDoubleSpinBox*>(editor);
        if (!w)
            return;
        w->setValue(index.model()->data(index, Qt::EditRole).toDouble());
    }
    else if (2 == index.column())
    {
        QLineEdit* w = dynamic_cast<QLineEdit*>(editor);
        if (!w)
            return;
        w->setText(index.model()->data(index, Qt::EditRole).toString());
    }
}

void add_note_table_delegate::setModelData(QWidget * editor, QAbstractItemModel * model, const QModelIndex & index) const
{
    assert(3 > index.column());
    if (0 == index.column())
    {
        QComboBox* w = dynamic_cast<QComboBox*>(editor);
        if (!w)
            return;
        model->setData(index, w->currentText(), Qt::EditRole);
    }
    else if (1 == index.column())
    {
        QDoubleSpinBox* w = dynamic_cast<QDoubleSpinBox*>(editor);
        if (!w)
            return;
        model->setData(index, w->value(), Qt::EditRole);
    }
    else if (2 == index.column())
    {
        QLineEdit* w = dynamic_cast<QLineEdit*>(editor);
        if (!w)
            return; 
        model->setData(index, w->text(), Qt::EditRole);
    }
}
