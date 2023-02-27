

#include "mainwindow.h"
#include "qdebug.h"
#include "qfileinfo.h"
#include "qsqlquery.h"
#include "ui_mainwindow.h"
#include "tablemodel.h"
#include "Values.h"
#include <QVariant>

struct MainWindowPrivate
{
    TableModel tm;
};

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    ,p(new MainWindowPrivate)
{
    //Q_OBJECT
    QSqlQueryModel *qm = new QSqlQueryModel(this);
    QString databaseName = "default";
    QFileInfo databaseFileName(databaseName + ".sqlite");
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", databaseName);
    db.setDatabaseName(databaseFileName.absoluteFilePath());
    db.open();
    qm->setQuery("SELECT * FROM example", db);
    p->tm.setSourceModel(qm);
    ui->setupUi(this);
    this->ui->tableView->setModel(&p->tm);
    connect(ui->tableView, SIGNAL(clicked(QModelIndex)), this, SLOT(on_tableView_clicked(QModelIndex)));

}

void MainWindow::on_tableView_clicked(const QModelIndex& index)
{
    if (index.column() ==0)
    {
        if (p->tm.checkbox.chk.size())
        {
            qDebug()<<"checkbox clicked";
            p->tm.markable();
        }
        else
        {
            p->tm.ReMove();
        }
    }
}

MainWindow::~MainWindow()
{
  delete ui;
}
