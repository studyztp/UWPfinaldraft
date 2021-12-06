#ifndef NUMBER_H
#define NUMBER_H
#include "token.h"
#include <math.h>

class Number: public Token
{
public:
    Number();
    Number(const double& item, const bool ifnegative = false);
    Number(const string& item, const bool ifnegative = false);
    double given_symbo_value(const string& item);
    virtual int get_type() const;
    virtual int get_prec() const;
    virtual double get_value()const;
    Number& operator=(const double& item);
    friend ostream& operator<<(ostream& outs, const Number& item)
    {
        outs<< item._value;
        return outs;
    }
private:
    double _value;
    bool negative;

};

#endif // NUMBER_H
