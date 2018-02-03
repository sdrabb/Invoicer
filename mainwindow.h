#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "receiver_settings.h"
#include "invoice_settings.h"
#include "constant_defs.h"
#include "article_settings.h"
#include "article2invoice_settings.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void populateDataItem();



private slots:
    void on_action_new_invoice_triggered();
    void on_action_settings_receiver_triggered();

    void on_receiver_choiches_clicked(const QModelIndex &index);

    void on_delete_selected_invoiice_button_clicked();

    void on_pushButton_clicked();

    void on_show_invoice_button_clicked();

    void on_actionaggiungi_rimuovi_articolo_triggered();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    Article2Invoice_settings *art2inv;
    Receiver_settings *rec_settings_view;
    Invoice_settings *invoice_settings_view;
    Article_settings *article_settings_view;


    int selected_receiver;

    QSqlTableModel *receiver_model;
    QSqlTableModel *invoice_model;
    QSqlTableModel *article_model;
    QSqlTableModel *article2invoice_model;

    QSqlDatabase db;

    bool initDatabase();
    bool closeDatabase();

};

#endif // MAINWINDOW_H
