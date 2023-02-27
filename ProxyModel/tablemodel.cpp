#include "tablemodel.h"
#include "mainwindow.h"

#include <QModelIndex>
#include <QDebug>
#include <QPixmap>
#include <QIcon>
#include <QDir>
#include <cmath>
#include <QVariant>

enum class headers {Check, Filed1, Field2, Field3};


TableModel::TableModel(QObject *parent) :QSortFilterProxyModel(parent)
{
}

int TableModel::rowCount(const QModelIndex &) const
{
    return QSortFilterProxyModel::rowCount() + svalues.count();
}

int TableModel::columnCount(const QModelIndex &) const
{
    return 4;
}

QVariant TableModel::data( const QModelIndex &index, int role ) const
{
    int rw = index.row();
    bool vir = rw<3;
    headers h = static_cast<headers>(index.column());
    QVariant value;
        switch ( role )
        {
            case Qt::DisplayRole: //string
            {
                switch (h)
                {
                    case headers::Check:
                    {
                        return QVariant();
                    }
                   default:
                    {
                        value = QSortFilterProxyModel::data(index, role);
                        if (!vir) value = this->svalues.at(index.row()-3).getValueByIndex(index.row());}
                        return value;
                    }
            break;
            case Qt::CheckStateRole:
                {
                   switch (index.column())
                   {
                   case 0:
                   {
                       if (index.row()<3)
                       {
                           bool ch = this->checkbox.getCheck(index.row()).toBool();
                           return ch ? Qt::Checked : Qt::Unchecked;
                       }
                       else
                            return QVariant();
                   }
                   default:
                       return QVariant();
                   }
                 }
               break;
            default:
                break;
        }
    }
    return value;
}

void TableModel::spopulate(QList<TableData> newValues)
{
    this->beginResetModel();
    this->beginInsertRows(QModelIndex(), 0, 0);
        this->svalues= newValues;
    endInsertRows();
    endResetModel();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return QVariant();
}

bool TableModel::setData(const QModelIndex & index, const QVariant & value, int role = Qt::EditRole)
{
    if(static_cast<headers>(index.column()) == headers::Check && role == Qt::CheckStateRole)
    {
        checkbox.setCheck(index.row(), value.toBool());
    }
    return true;
};

void TableModel::markable()
{
    QList<TableData> values;
    float mval=0;
    for (auto const& v: checkbox.chk)
    {
         mval+=pow(2, v.first);
    }
    for (int id =1 ; id <4; id++)
    {
        mean.setValueByIndex(id, mval);
    }
    if (svalues.size())
        svalues.removeLast();
    values.append(mean);
    spopulate(values);
    values.removeLast();
}


void TableModel::ReMove()
{
    if (svalues.size())
    {
        this->beginResetModel();
            this->svalues.clear();
        this->endResetModel();
    }
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    if (index.column() == 0)
       flags |= Qt::ItemIsUserCheckable;
    return flags;
}
