#include "article_settings.h"
#include "ui_article_settings.h"
#include "constant_defs.h"
#include <QMessageBox>

Article_settings::Article_settings(QSqlTableModel *article_model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Article_settings)
{
    ui->setupUi(this);
    this->article_model = article_model;
    ui->tableView->setModel(article_model);
}

Article_settings::~Article_settings()
{
    delete ui;
}

void Article_settings::on_pushButton_clicked()
{


    /* add data to the model */
    int row=0;
    article_model->insertRows(row,1);
    article_model->setData( article_model->index(row,ARTICLE_NAME_COLUMN), ui->lineEdit->text() );
    article_model->setData( article_model->index(row,ARTICLE_PRICE_COLUMN), ui->lineEdit_2->text());


    /* verify the write on db */
    bool flag = article_model->submitAll();
    if(flag==false)
        QMessageBox::critical(0,"failed", "cannot save article.");
    else{

        QMessageBox::information(0,"success","article saved successfully.");

    }
}
