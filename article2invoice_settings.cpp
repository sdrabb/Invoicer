#include "article2invoice_settings.h"
#include "ui_article2invoice_settings.h"
#include "qmessagebox.h"

Article2Invoice_settings::Article2Invoice_settings(QSqlTableModel *article2invoice_model, QSqlTableModel *invoice_model, QSqlTableModel *article_model,QItemSelectionModel* select_invoice, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Article2Invoice_settings)
{
    ui->setupUi(this);
    this->invoice_model = invoice_model;
    this->article_model = article_model;
    this->article2invoice_model = article2invoice_model;

    ui->tableView->setModel(article2invoice_model);


    int selected_invoice = select_invoice->selectedRows().first().row();
    current_invoice_id = invoice_model->index(selected_invoice,INVOICE_ID_COLUMN).data().toInt();
    QString invoice_id = invoice_model->index(selected_invoice,INVOICE_ID_COLUMN).data().toString();
    ui->label_5->setText(invoice_id);

    ui->comboBox->setModel(article_model);
    ui->comboBox->setModelColumn(ARTICLE_NAME_COLUMN);

}

Article2Invoice_settings::~Article2Invoice_settings()
{
    delete ui;
}

void Article2Invoice_settings::on_pushButton_clicked()
{

    int row_combo = ui->comboBox->currentIndex();
    QModelIndex idx = ui->comboBox->model()->index(row_combo, ARTICLE_ID_COLUMN); // first column
    QVariant data = ui->comboBox->model()->data(idx);
    int current_article_id = data.toInt();
//    QItemSelectionModel *select_article = ui->comboBox->selectionModel();
//    int selected_article = select_article->selectedRows().first().row();

//    int current_article_id = invoice_model->index(selected_article,ARTICLE_ID_COLUMN).data().toInt();

    /* add data to the model */
    int row=0;
    article2invoice_model->insertRows(row,1);
    article2invoice_model->setData( article_model->index(row,ARTICLE2INVOICE_ARTICLE_COLUMN), current_article_id );
    article2invoice_model->setData( article_model->index(row,ARTICLE2INVOICE_INVOICE_COLUMN), current_invoice_id );
    article2invoice_model->setData( article_model->index(row,ARTICLE2INVOICE_QUANTITY_COLUMN), ui->lineEdit->text());


    /* verify the write on db */
    bool flag = article2invoice_model->submitAll();
    if(flag==false)
        QMessageBox::critical(0,"failed", "cannot save article.");
    else{

        QMessageBox::information(0,"success","article saved successfully.");

    }
}
