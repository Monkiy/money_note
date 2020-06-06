#pragma once
#include <QItemDelegate>

class add_note_table_delegate :public QItemDelegate
{
    Q_OBJECT
public:
    add_note_table_delegate(QObject *parent = 0);
    //void paint(QPainter *painter, const QStyleOptionViewItem &option,const QModelIndex &index) const;
    //QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const;
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,const QModelIndex &index) const;

    inline void set_note_types(const QStringList &note_types) { __note_types = note_types; }
private:
    QStringList __note_types;
};