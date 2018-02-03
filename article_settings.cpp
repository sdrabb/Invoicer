#include "article_settings.h"
#include "ui_article_settings.h"

Article_settings::Article_settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Article_settings)
{
    ui->setupUi(this);
}

Article_settings::~Article_settings()
{
    delete ui;
}
