#ifndef TOKEN_H
#define TOKEN_H
#include <iostream>
#include "NUMBERS.h"
using namespace std;

class Token
{
public:
    Token();
    virtual int get_type() const;
    virtual int get_prec() const;
    friend ostream& operator<<(ostream& outs, const Token& item)
    {
        outs<< 0;
        return outs;
    }
private:


};

#endif // TOKEN_H
