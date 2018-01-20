#ifndef RECEIVER_H
#define RECEIVER_H

#include <QString>

class Receiver
{
public:
    Receiver();
    QString getName() const;
    void setName(const QString &value);

    QString getSurname() const;
    void setSurname(const QString &value);

    QString getCity() const;
    void setCity(const QString &value);

    QString getProvince() const;
    void setProvince(const QString &value);

    qint16 getFiscal_code() const;
    void setFiscal_code(const qint16 &value);

    qint16 getPi() const;
    void setPi(const qint16 &value);

    qint16 getCap() const;
    void setCap(const qint16 &value);

private:
    QString name;
    QString surname;
    QString city;
    QString province;

    qint16 fiscal_code;
    qint16 pi;
    qint16 cap;



};

#endif // RECEIVER_H
