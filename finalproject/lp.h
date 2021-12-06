#ifndef LP_H
#define LP_H
#include "token.h"

class LP: public Token
{
public:
    LP();
    int get_prec() const;
    int get_type() const;
private:

};

#endif // LP_H
