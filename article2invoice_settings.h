#ifndef ARTICLE2INVOICE_SETTINGS_H
#define ARTICLE2INVOICE_SETTINGS_H

#include <QDialog>
#include <QSqlTableModel>
#include <invoice_settings.h>
#include <qitemselectionmodel.h>
#include <QDialog>

namespace Ui {
class Article2Invoice_settings;
}

class Article2Invoice_settings : public QDialog
{
    Q_OBJECT

public:
    explicit Article2Invoice_settings(QSqlTableModel *article2invoice_model, QSqlTableModel *invoice_model, QSqlTableModel *article_model,QItemSelectionModel* select_invoice, QWidget *parent = 0);
    ~Article2Invoice_settings();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Article2Invoice_settings *ui;
    QSqlTableModel *invoice_model;
    QSqlTableModel *article_model;
    QSqlTableModel *article2invoice_model;

    int current_invoice_id;
};

#endif // ARTICLE2INVOICE_SETTINGS_H
