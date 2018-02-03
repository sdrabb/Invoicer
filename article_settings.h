#ifndef ARTICLE_SETTINGS_H
#define ARTICLE_SETTINGS_H

#include <QDialog>

namespace Ui {
class Article_settings;
}

class Article_settings : public QDialog
{
    Q_OBJECT

public:
    explicit Article_settings(QWidget *parent = 0);
    ~Article_settings();

private:
    Ui::Article_settings *ui;
};

#endif // ARTICLE_SETTINGS_H
