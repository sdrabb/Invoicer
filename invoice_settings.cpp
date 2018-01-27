#include "invoice_settings.h"
#include "ui_invoice_settings.h"
#include <QCoreApplication>
#include <QMessageBox>

Invoice_settings::Invoice_settings( QSqlTableModel *invoice_model, QSqlTableModel *receiver_model, QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::Invoice_settings)
{
    ui->setupUi(this);

    /* model connections */
    this->invoice_model = invoice_model;
    this->receiver_model = receiver_model;

    populate_combo_box();

}

Invoice_settings::~Invoice_settings()
{
    delete ui;
}

/**
 * @brief add all the receivers to the combobox
 *
 * @author alb3rto
 * @date 27/01/2017
 * @return void
 */
void Invoice_settings::populate_combo_box()
{
    ui->owner_combobox->setModel(this->receiver_model);

}


/**
 * @brief add new invoice to the invoice_model when add button is clicked
 *
 * @author alb3rto
 * @date 27/01/2017
 * @return void
 */
void Invoice_settings::on_add_new_clicked()
{
    /* get owner id from the combobox */
    QModelIndex idx = ui->owner_combobox->model()->index(ui->owner_combobox->currentIndex(), RECEIVER_ID_COLUMN); // first column
    QVariant data = ui->owner_combobox->model()->data(idx);
    int type_id = data.toInt();
    qDebug("%d",type_id);

    /* add data to the model */
    int row=0;
    invoice_model->insertRows(row,1);
    invoice_model->setData( invoice_model->index(row,INVOICE_PROGRESSIVE_NUMBER_COLUMN), invoice_model->rowCount()+1 );
    invoice_model->setData( invoice_model->index(row,INVOICE_OWNER_COLUMN), type_id);
    invoice_model->setData( invoice_model->index(row,INVOICE_DATE_COLUMN), ui->dateEdit->text());
    invoice_model->setData( invoice_model->index(row,INVOICE_TAXABLE_COLUMN), ui->taxable_line_edit->text().toFloat());

    /* verify the write on db */
    bool flag = invoice_model->submitAll();
    if(flag==false)
        QMessageBox::critical(0,"failed", "cannot save invoice.");
    else{

        QMessageBox::information(0,"success","invoice saved successfully.");

        /* close the dialog */
        this->close();

    }


}
