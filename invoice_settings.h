#ifndef INVOICE_SETTINGS_H
#define INVOICE_SETTINGS_H

#include <QDialog>

namespace Ui {
class Invoice_settings;
}

class Invoice_settings : public QDialog
{
    Q_OBJECT

public:
    explicit Invoice_settings(QWidget *parent = 0);
    ~Invoice_settings();

private:
    Ui::Invoice_settings *ui;
};

#endif // INVOICE_SETTINGS_H
