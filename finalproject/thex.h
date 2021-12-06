#ifndef THEX_H
#define THEX_H
#include "number.h"

class theX:public Number
{
public:
    theX();
    theX(bool if_negative = false);
    int get_prec() const;
    int get_type() const;
    bool if_negative() const
    {
        return negative;
    }
    double get_value()const;
    theX& operator=(const double& item);
    friend ostream& operator<<(ostream& outs, const theX& item)
    {
        if(item.negative)
            outs<<"-X";
        else
            outs<<"X";
        return  outs;
    }
private:
    double _value;
    bool negative = false;
};

#endif // THEX_H
