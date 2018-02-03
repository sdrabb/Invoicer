#ifndef RECEIVER_SETTINGS_H
#define RECEIVER_SETTINGS_H

#include <QDialog>
#include <QSqlDatabase>
#include <QSqlTableModel>
#include "constant_defs.h"

namespace Ui {
class Receiver_settings;
}

class Receiver_settings : public QDialog
{
    Q_OBJECT

public:
    explicit Receiver_settings(QWidget *parent = 0);
    ~Receiver_settings();

    void populateDataItem();

public slots:
    void add_new_receiver();
    void save_receiver();


private:
    Ui::Receiver_settings *ui;
    QSqlTableModel *model;
    QSqlDatabase db;


    bool initDatabase();
    bool closeDatabase();
};

#endif // RECEIVER_SETTINGS_H
