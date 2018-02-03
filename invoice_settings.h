#ifndef INVOICE_SETTINGS_H
#define INVOICE_SETTINGS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "constant_defs.h"

namespace Ui {
class Invoice_settings;
}

class Invoice_settings : public QDialog
{
    Q_OBJECT

public:
    explicit Invoice_settings(QSqlTableModel *invoice_model, QSqlTableModel *receiver_model, QWidget *parent = 0);
    ~Invoice_settings();

    /**
    * @brief add all the receivers to the combobox
    *
    * @author alb3rto
    * @date 27/01/2017
    * @return void
    */
    void populate_combo_box();


    Ui::Invoice_settings *getUi() const;

private slots:


    /**
    * @brief add new invoice to the invoice_model when add button is clicked
    *
    * @author alb3rto
    * @return void
    */
    void on_add_new_clicked();

private:
    Ui::Invoice_settings *ui;

    QSqlTableModel *invoice_model;
    QSqlTableModel *receiver_model;


};

#endif // INVOICE_SETTINGS_H
