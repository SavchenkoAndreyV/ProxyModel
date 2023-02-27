#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QModelIndex>
#include <map>
#include "Values.h"
#include <QSortFilterProxyModel>
#include <QAbstractItemModel>
#include <mainwindow.h>

class TableModel : public QSortFilterProxyModel //proxy
{   
   Q_OBJECT

public:
    TableModel(QObject *parent=nullptr);
    int rowCount(const QModelIndex &) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
    void populate(QList<TableData> newValues);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    void markable();
    Qt::ItemFlags flags(const QModelIndex&) const;
    QList<TableData> values;
    TableData checkbox, mean;
    void ReMove();
};

#endif // TABLEMODEL_H
