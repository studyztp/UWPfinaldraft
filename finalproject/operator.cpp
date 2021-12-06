#include "operator.h"

Operator::Operator()
{
    _value ="";
    _prec = 99;
}
Operator::Operator(const string& item)
{
    _value = item;
    _prec = is_prec();
}
int Operator::get_type() const
{
    return OPERATOR;
}
int Operator::get_prec() const
{
    return _prec;
}
int Operator::is_prec() const
{
    if(_value=="+"||_value =="-")
        return 1;
    if(_value=="*"||_value == "/")
        return 2;
    if(_value=="^")
        return 3;
    return 99;
}
string Operator:: get_value()const
{
    return _value;
}
double Operator:: calculation(const double& a, const double&b)
{
    switch (_prec) {
    case 1:
        if(_value=="+")
            return ( a +b);
        else
            return ( a -b);
    case 2:
        if(_value == "*")
            return (a*b);
        else
            return (a/b);
    case 3:
        return (pow(a,b));
    default:
        break;
    }

}
