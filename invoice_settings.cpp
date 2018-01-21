#include "invoice_settings.h"
#include "ui_invoice_settings.h"

Invoice_settings::Invoice_settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Invoice_settings)
{
    ui->setupUi(this);
}

Invoice_settings::~Invoice_settings()
{
    delete ui;
}
