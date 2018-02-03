#include "article2invoice_settings.h"
#include "ui_article2invoice_settings.h"

Article2Invoice_settings::Article2Invoice_settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Article2Invoice_settings)
{
    ui->setupUi(this);
}

Article2Invoice_settings::~Article2Invoice_settings()
{
    delete ui;
}
