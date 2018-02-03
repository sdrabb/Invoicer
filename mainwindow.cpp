#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QTextDocument>
#include <QPrinter>
#include <QPdfWriter>
#include <QDesktopServices>
#include <QDate>
#include "article2invoice_settings.h"

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
    ui->invoices->verticalHeader()->setVisible(true);
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


    /* populate table related to articles */
    article_model = new QSqlTableModel(this,db);
    article_model->setTable("article");
    article_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    article_model->select();


    /* populate table related to article2 invoice */
    article2invoice_model = new QSqlTableModel(this,db);
    article2invoice_model->setTable("Article2Invoice");
    article2invoice_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    article2invoice_model->select();



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

void MainWindow::on_pushButton_clicked()
{
    on_action_new_invoice_triggered();
}

void MainWindow::on_show_invoice_button_clicked()
{
    QItemSelectionModel *select_invoice = ui->invoices->selectionModel();
    int selected_invoice = select_invoice->selectedRows().first().row();

    int selected_receiver;

//    QItemSelectionModel *select_receiver = ui->receiver_choiches->selectionModel();
//    int selected_receiver = select_receiver->selectedRows().first().row();

    QString invoice_year = QString::number(QDate(invoice_model->index(selected_invoice,INVOICE_DATE_COLUMN).data().toDate()).year());
    QString invoice_progressive_number = invoice_model->index(selected_invoice,INVOICE_PROGRESSIVE_NUMBER_COLUMN).data().toString();
    QString invoice_date = invoice_model->index(selected_invoice,INVOICE_DATE_COLUMN).data().toString();
    float invoice_taxable = invoice_model->index(selected_invoice,INVOICE_TAXABLE_COLUMN).data().toFloat();
    QString invoice_iva_percentage = QString::number(SELF_IVA);
    int invoice_owner = invoice_model->index(selected_invoice,INVOICE_OWNER_COLUMN).data().toInt();


    QString sender_city = SELF_CITY;
    QString sender_name = SELF_NAME;
    QString sender_surname = SELF_SURNAME;
    QString sender_address = SELF_ADDRESS;
    QString sender_civic_number = QString::number(SELF_CIVIC_NUMBER);
    QString sender_piva = SELF_PIVA;
    QString sender_fiscal_code = SELF_FISCAL_CODE;

    for(int i = 0; i < receiver_model->rowCount(); i++)
    {
        if (receiver_model->index(i, RECEIVER_ID_COLUMN).data().toInt() == invoice_owner){
            selected_receiver = i;
            break;
        }

    }

    QString receiver_name = receiver_model->index(selected_receiver,RECEIVER_NAME_COLUMN).data().toString();
    QString receiver_surname = receiver_model->index(selected_receiver,RECEIVER_SURNAME_COLUMN).data().toString();
    QString receiver_address = receiver_model->index(selected_receiver,RECEIVER_ADDRESS_COLUMN).data().toString();
    QString receiver_piva = receiver_model->index(selected_receiver,RECEIVER_PIVA_COLUMN).data().toString();
    QString receiver_fiscal_code = receiver_model->index(selected_receiver,RECEIVER_FISCAL_CODE_COLUMN).data().toString();
    QString receiver_cap = receiver_model->index(selected_receiver,RECEIVER_CAP_COLUMN).data().toString();
    QString receiver_province = receiver_model->index(selected_receiver,RECEIVER_PROVINCE_COLUMN).data().toString();
    QString receiver_civic_number = receiver_model->index(selected_receiver,RECEIVER_CIVIC_NUMBER_COLUMN).data().toString();


    float iva = (invoice_taxable/100) * SELF_IVA;
    float total_with_iva = ((invoice_taxable/100) * SELF_IVA) + invoice_taxable;
    float rit_acc = ((invoice_taxable/2)/100) *SELF_RIT_ACC;
    float enasarco = (invoice_taxable/100) *SELF_ENASARCO;
    float total = (((invoice_taxable/100) * SELF_IVA) + invoice_taxable) - (((invoice_taxable/100) *SELF_ENASARCO)+(((invoice_taxable/2)/100) *SELF_RIT_ACC));

    QString html =
    "<div align=right>"
       + sender_city +", "+invoice_date+
    "</div>"
    "<div align=left>"
       +sender_name+" "+sender_surname+"<br>"
       +sender_address+" "+sender_civic_number+"<br>"
       +sender_city+"<br>"
       +"P.I. "+sender_piva+"<br>"
       +"C.F. "+sender_fiscal_code+"<br>"
    "</div>"
    "<h6 align=center>FATTURA N."+invoice_progressive_number+"/"+invoice_year+" </h6>"+
    "<h6 align=center>"+sender_city +" LI  "+invoice_date +" </h6>"
    "<div align=right >"
       "<table cellspacing=20 >"
           "<tr>"
             "<td>SPETT.LE</td>"
           "</tr>"
           "<tr>"
             "<td>"+receiver_name+ " " +receiver_surname +"</td>"
           "</tr>"
           "<tr>"
             "<td>"+receiver_address +" "+receiver_civic_number+"</td>"
           "</tr>"
            "<tr>"
              "<td>P.I. "+receiver_piva+"</td>"
            "</tr>"
           "<tr>"
             "<td>Cod.Fisc. "+receiver_fiscal_code+"</td>"
           "</tr>"
          "<tr>"
            "<td>"+receiver_cap+" "+receiver_province+"</td>"
          "</tr>"
       "</table> "
    "</div>"
    "<div>"
       "<table cellspacing=20 >"
            "<tr>"
              "<td>PROVVIGIONI MATURATE</td>"
              "<td>IMPONIBILE</td>"
              "<td>&euro;.</td>"
              "<td>"+QString::number(invoice_taxable)+"</td>"
            "</tr>"
            "<tr>"
              "<td></td>"
              "<td>IVA "+invoice_iva_percentage+"&#37;</td>"
              "<td>&euro;.</td>"
              "<td>"+ QString::number( iva ) +"</td>"
            "</tr>"
             "<tr>"
               "<td></td>"
               "<td> TOTALE </td>"
               "<td> &euro;.</td>"
               "<td>"+ QString::number( total_with_iva )  +"</td>"
             "</tr>"
             "<tr>"
               "<td></td>"
               "<td> RIT.ACCONTO "+QString::number(SELF_RIT_ACC)+" su 50&#37; IMP.</td>"
               "<td> &euro;.</td>"
               "<td>"+ QString::number(rit_acc)  +"</td>"
             "</tr>"
             "<tr>"
               "<td></td>"
               "<td> ENASARCO "+QString::number(SELF_ENASARCO)+"</td>"
               "<td> &euro;.</td>"
               "<td>"+ QString::number(enasarco)  +"</td>"
             "</tr>"
             "<tr>"
               "<td></td>"
               "<td> TOTALE </td>"
               "<td> &euro;.</td>"
               "<td>"+ QString::number(total )  +"</td>"
           "</tr>"
        "</table> "
    "</div>";

    QTextDocument document;
    document.setHtml(html);


    QPdfWriter printer("results.pdf");

    printer.setPageMargins(QMarginsF(15, 15, 15, 15));
    QDesktopServices::openUrl(QUrl("results.pdf"));

    document.print(&printer);
}

void MainWindow::on_actionaggiungi_rimuovi_articolo_triggered()
{
    this->article_settings_view = new Article_settings(this->article_model, this);
    this->article_settings_view->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    QItemSelectionModel *select_invoice = ui->invoices->selectionModel();
    this->art2inv = new Article2Invoice_settings(this->article2invoice_model,this->invoice_model,this->article_model,select_invoice,this);
    this->art2inv->show();
}


