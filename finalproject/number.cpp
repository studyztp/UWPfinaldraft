#include "number.h"

Number::Number()
{
    _value = 0;
    negative = false;
}
Number::Number (const double& item, const bool ifnegative)
{
    _value = item;
    negative = ifnegative;
}
Number::Number(const string& item, const bool ifnegative)
{
    _value = given_symbo_value(item);
    negative = ifnegative;
}
double Number:: given_symbo_value(const string& item)
{
    if(item == "PI")
    {
        if(negative)
            return -(M_PI);
        return M_PI;
    }
    if(item == "E")
    {
        if(negative)
            return -(exp(1.0));
        return exp(1.0);
    }

}
Number& Number::operator=(const double& item)
{
    _value = item;
    return *this;
}
int Number::get_type() const
{
    return NUMBER;
}
int Number::get_prec() const
{
    return  99;
}
double Number::get_value()const
{
    if(negative)
        return -(_value);
    return _value;
}
