#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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
    ui->receiver_choiches->hideColumn(RECEIVER_SURNAME_COLUMN);
    ui->receiver_choiches->hideColumn(RECEIVER_ADDRESS_COLUMN);
    ui->receiver_choiches->hideColumn(RECEIVER_CIVIC_NUMBER_COLUMN);
    ui->receiver_choiches->hideColumn(RECEIVER_CAP_COLUMN);
    ui->receiver_choiches->hideColumn(RECEIVER_PROVINCE_COLUMN);
    ui->receiver_choiches->hideColumn(RECEIVER_PIVA_COLUMN);
    ui->receiver_choiches->hideColumn(RECEIVER_FISCAL_CODE_COLUMN);
    ui->receiver_choiches->hideColumn(RECEIVER_MAIL_COLUMN);
    ui->receiver_choiches->hideColumn(RECEIVER_ID_COLUMN);


     /* populate table related to invoices */
    invoice_model = new QSqlTableModel(this, db);
    invoice_model->setTable("invoice");
    invoice_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    invoice_model->select();


    invoice_model->setHeaderData(INVOICE_PROGRESSIVE_NUMBER_COLUMN, Qt::Horizontal, tr("n.p."));
    invoice_model->setHeaderData(INVOICE_TAXABLE_COLUMN, Qt::Horizontal, tr("imponibile"));

    ui->invoices->setModel(invoice_model);
    ui->invoices->setAlternatingRowColors(true);
    receiver_model->setHeaderData(INVOICE_OWNER_COLUMN, Qt::Horizontal, tr("progressive"));



}



void MainWindow::on_action_new_invoice_triggered()
{

    this->invoice_settings_view = new Invoice_settings(this->invoice_model,this->receiver_model,this);
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
    qDebug("%d",receiver_model->index(index.row() , RECEIVER_ID_COLUMN).data().toInt());

    invoice_model->setFilter("owner = " + receiver_model->index(index.row() , RECEIVER_ID_COLUMN).data().toString());
//    QSqlQuery query;
//    query.exec("SELECT name, salary FROM employee WHERE salary > 50000");

}

void MainWindow::on_delete_selected_invoiice_button_clicked()
{
    QItemSelectionModel *select = ui->invoices->selectionModel();


//    select->hasSelection(); //check if has selection
//    select->selectedRows(); // return selected row(s)
//    select->selectedColumns(); // return selected column(s)


    this->invoice_model->removeRow(select->selectedRows().first().row());

    /* verify the write on db */
    bool flag = invoice_model->submitAll();
    if(flag==false)
        QMessageBox::critical(0,"failed", "cannot remove invoice.");
    else{

        QMessageBox::information(0,"success","invoice removed successfully.");


    }
}
