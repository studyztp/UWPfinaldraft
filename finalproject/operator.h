#ifndef OPERATOR_H
#define OPERATOR_H
#include "token.h"
#include "math.h"

class Operator: public Token
{
public:
    Operator();
    Operator(const string& item);
    int get_type() const;
    int get_prec() const;
    int is_prec() const;
    double calculation(const double& a, const double&b);
    bool is_div() const
    {
        if(_value == "/")
            return true;
        else
            return false;
    }
    string get_value()const;
    friend ostream& operator<<(ostream& outs, const Operator& item)
    {
        outs<< item._value;
        return outs;
    }
private:
    string _value;
    int _prec;

};

#endif // OPERATOR_H
