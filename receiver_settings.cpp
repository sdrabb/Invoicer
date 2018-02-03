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
    model->setHeaderData(RECEIVER_NAME_COLUMN, Qt::Horizontal, tr("nome"));
    model->setHeaderData(RECEIVER_SURNAME_COLUMN, Qt::Horizontal, tr("cognome"));
    model->setHeaderData(RECEIVER_ADDRESS_COLUMN, Qt::Horizontal, tr("indirizzo"));
    model->setHeaderData(RECEIVER_CIVIC_NUMBER_COLUMN, Qt::Horizontal, tr("numero civico"));
    model->setHeaderData(RECEIVER_CAP_COLUMN, Qt::Horizontal, tr("cap"));
    model->setHeaderData(RECEIVER_PROVINCE_COLUMN, Qt::Horizontal, tr("provincia"));
    model->setHeaderData(RECEIVER_PIVA_COLUMN, Qt::Horizontal, tr("p.iva"));
    model->setHeaderData(RECEIVER_FISCAL_CODE_COLUMN, Qt::Horizontal, tr("codice fiscale"));
    model->setHeaderData(RECEIVER_MAIL_COLUMN, Qt::Horizontal, tr("mail"));

    ui->tableView->setModel(model);
    ui->tableView->setAlternatingRowColors(true);

}

void Receiver_settings::add_new_receiver()
{
    int row=0;
    model->insertRows(row,1);
    model->setData(model->index(row,RECEIVER_NAME_COLUMN),ui->name_line_edit->text());
    model->setData(model->index(row,RECEIVER_SURNAME_COLUMN),ui->surname_line_edit->text());
    model->setData(model->index(row,RECEIVER_ADDRESS_COLUMN),ui->address_line_edit->text());
    model->setData(model->index(row,RECEIVER_CIVIC_NUMBER_COLUMN),ui->civic_number_line_edit->text());
    model->setData(model->index(row,RECEIVER_CAP_COLUMN),ui->cap_line_edit->text());
    model->setData(model->index(row,RECEIVER_PROVINCE_COLUMN),ui->province_line_edit->text());
    model->setData(model->index(row,RECEIVER_PIVA_COLUMN),ui->piva_line_edit->text());
    model->setData(model->index(row,RECEIVER_FISCAL_CODE_COLUMN),ui->fiscal_code_line_edit->text());
    model->setData(model->index(row,RECEIVER_MAIL_COLUMN),ui->mail_line_edit->text());
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
