#ifndef ARTICLE_SETTINGS_H
#define ARTICLE_SETTINGS_H

#include <QDialog>
#include <QSqlTableModel>

namespace Ui {
class Article_settings;
}

class Article_settings : public QDialog
{
    Q_OBJECT

public:
    explicit Article_settings(QSqlTableModel *article_model,QWidget *parent = 0);
    ~Article_settings();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Article_settings *ui;
    QSqlTableModel *article_model;
};

#endif // ARTICLE_SETTINGS_H
