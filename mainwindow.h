#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "receiver_settings.h"
#include "invoice_settings.h"

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

private:
    Ui::MainWindow *ui;
    Receiver_settings *rec_settings_view;
    Invoice_settings *invoice_settings_view;

    int selected_receiver;

    QSqlTableModel *receiver_model;
    QSqlTableModel *invoice_model;

    QSqlDatabase db;

    bool initDatabase();
    bool closeDatabase();

};

#endif // MAINWINDOW_H
