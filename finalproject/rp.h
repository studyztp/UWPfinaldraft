#ifndef RP_H
#define RP_H
#include "token.h"

class RP:public Token
{
public:
    RP();
    int get_type() const;
    int get_prec() const;
private:
};

#endif // RP_H
