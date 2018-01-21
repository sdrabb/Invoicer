#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    if (initDatabase() == true)
        qDebug("db opened");
    else
        qDebug("db not opened");

    populateDataItem();

}

MainWindow::~MainWindow()
{
    delete ui;

}


void MainWindow::populateDataItem()
{
    /* populate table related to receiver */

    receiver_model = new QSqlTableModel(this, db);
    receiver_model->setTable("receiver");
    receiver_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    receiver_model->select();
    receiver_model->setHeaderData(0, Qt::Horizontal, tr("destinatario"));

    ui->receiver_choiches->setModel(receiver_model);
    ui->receiver_choiches->setAlternatingRowColors(true);
    ui->receiver_choiches->hideColumn(1);
    ui->receiver_choiches->hideColumn(2);
    ui->receiver_choiches->hideColumn(3);
    ui->receiver_choiches->hideColumn(4);
    ui->receiver_choiches->hideColumn(5);
    ui->receiver_choiches->hideColumn(6);
    ui->receiver_choiches->hideColumn(7);
    ui->receiver_choiches->hideColumn(8);
    ui->receiver_choiches->hideColumn(9);


     /* populate table related to invoices */


    invoice_model = new QSqlTableModel(this, db);
    invoice_model->setTable("invoice");
    invoice_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    invoice_model->select();


    invoice_model->setHeaderData(1, Qt::Horizontal, tr("n.p."));
    invoice_model->setHeaderData(2, Qt::Horizontal, tr("imponibile"));

    ui->invoices->setModel(invoice_model);
    ui->invoices->setAlternatingRowColors(true);
    receiver_model->setHeaderData(3, Qt::Horizontal, tr("progressive"));



}



void MainWindow::on_action_new_invoice_triggered()
{

    this->invoice_settings_view = new Invoice_settings(this);
    this->invoice_settings_view->show();

}

void MainWindow::on_action_settings_receiver_triggered()
{

    this->rec_settings_view = new Receiver_settings(this);
    this->rec_settings_view->show();



    QString text_to_show = "<p>Merciai Luigi</p>";
//    ui->receiver_choiches->setText(text_to_show);
}


bool MainWindow::initDatabase()
{
     QString path = QCoreApplication::applicationDirPath() + "/db_invoice_manager.db";
     QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
     db.setDatabaseName(path);
     return db.open();
}

bool MainWindow::closeDatabase()
{
   db.close();
}

void MainWindow::on_receiver_choiches_clicked(const QModelIndex &index)
{
    qDebug("%d",receiver_model->index(index.row() , 9).data().toInt());

    invoice_model->setFilter("owner = " + receiver_model->index(index.row() , 9).data().toString());
//    QSqlQuery query;
//    query.exec("SELECT name, salary FROM employee WHERE salary > 50000");

}
