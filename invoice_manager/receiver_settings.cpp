#include "receiver_settings.h"
#include "ui_receiver_settings.h"
#include <QCoreApplication>
#include <QMessageBox>

Receiver_settings::Receiver_settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Receiver_settings)
{

    ui->setupUi(this);
    if (initDatabase() == true)
        qDebug("db opened");
    else
        qDebug("db not opened");

    populateDataItem();

    connect(ui->add_new, SIGNAL(clicked(bool)),this,SLOT(add_new_receiver()));
    connect(ui->submit_button, SIGNAL(clicked(bool)),this,SLOT(save_receiver()));
}

Receiver_settings::~Receiver_settings()
{
    delete ui;
}



void Receiver_settings::populateDataItem()
{
    model=new QSqlTableModel(this, db);
    model->setTable("receiver");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();
    model->setHeaderData(0, Qt::Horizontal, tr("name"));
    model->setHeaderData(1, Qt::Horizontal, tr("Surname"));
    model->setHeaderData(2, Qt::Horizontal, tr("Address"));
    model->setHeaderData(3, Qt::Horizontal, tr("Civic number"));
    model->setHeaderData(4, Qt::Horizontal, tr("cap"));
    model->setHeaderData(5, Qt::Horizontal, tr("Province"));
    model->setHeaderData(6, Qt::Horizontal, tr("p.iva"));
    model->setHeaderData(7, Qt::Horizontal, tr("fiscal code"));
    model->setHeaderData(8, Qt::Horizontal, tr("mail"));

    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);

}

void Receiver_settings::add_new_receiver()
{
    int row=0;
    model->insertRows(row,1);
    model->setData(model->index(row,0),ui->name_line_edit->text());
    model->setData(model->index(row,1),ui->surname_line_edit->text());
    model->setData(model->index(row,2),ui->address_line_edit->text());
    model->setData(model->index(row,3),ui->civic_number_line_edit->text());
    model->setData(model->index(row,4),ui->cap_line_edit->text());
    model->setData(model->index(row,5),ui->province_line_edit->text());
    model->setData(model->index(row,6),ui->piva_line_edit->text());
    model->setData(model->index(row,7),ui->fiscal_code_line_edit->text());
    model->setData(model->index(row,8),ui->mail_line_edit->text());
}

void Receiver_settings::save_receiver()
{
    bool flag = model->submitAll();
    if(flag==false)
       QMessageBox::critical(0,"failed", "cannot save changes.");
    else
       QMessageBox::information(0,"success","changes saved successfully.");
//    qDebug( model->lastError());
//    qDebug(model.lastError());
}

bool Receiver_settings::initDatabase()
{
     QString path = QCoreApplication::applicationDirPath() + "/db_invoice_manager.db";
     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName(path);
     return db.open();
}

bool Receiver_settings::closeDatabase()
{
   db.close();
}
