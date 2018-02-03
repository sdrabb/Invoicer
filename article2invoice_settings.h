#ifndef ARTICLE2INVOICE_SETTINGS_H
#define ARTICLE2INVOICE_SETTINGS_H

#include <QDialog>

namespace Ui {
class Article2Invoice_settings;
}

class Article2Invoice_settings : public QDialog
{
    Q_OBJECT

public:
    explicit Article2Invoice_settings(QWidget *parent = 0);
    ~Article2Invoice_settings();

private:
    Ui::Article2Invoice_settings *ui;
};

#endif // ARTICLE2INVOICE_SETTINGS_H
