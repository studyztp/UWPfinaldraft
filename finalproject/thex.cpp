#include "thex.h"

theX::theX()
{
    _value = 0;
}
theX::theX(bool if_negative)
{
    negative = if_negative;
    _value =0;
}
int theX::get_prec() const
{
    return heyX;
}
int theX::get_type() const
{
    return NUMBER;
}
double theX::get_value() const
{
    return _value;
}
theX& theX::operator=(const double& item)
{
    _value = item;
    return *this;
}
