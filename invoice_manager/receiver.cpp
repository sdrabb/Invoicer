#include "receiver.h"

Receiver::Receiver()
{

}

QString Receiver::getName() const
{
    return name;
}

void Receiver::setName(const QString &value)
{
    name = value;
}

QString Receiver::getSurname() const
{
    return surname;
}

void Receiver::setSurname(const QString &value)
{
    surname = value;
}

QString Receiver::getCity() const
{
    return city;
}

void Receiver::setCity(const QString &value)
{
    city = value;
}

QString Receiver::getProvince() const
{
    return province;
}

void Receiver::setProvince(const QString &value)
{
    province = value;
}

qint16 Receiver::getFiscal_code() const
{
    return fiscal_code;
}

void Receiver::setFiscal_code(const qint16 &value)
{
    fiscal_code = value;
}

qint16 Receiver::getPi() const
{
    return pi;
}

void Receiver::setPi(const qint16 &value)
{
    pi = value;
}

qint16 Receiver::getCap() const
{
    return cap;
}

void Receiver::setCap(const qint16 &value)
{
    cap = value;
}
