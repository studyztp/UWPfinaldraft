#ifndef SHUNTINGYARD_H
#define SHUNTINGYARD_H
#include "features.h"
class ShuntingYard
{
public:
    ShuntingYard();
    Queue<Token*> profixing(const Queue<Token*>& in);
    Queue<Token*> get_profix()
    {
        return _profix;
    }
    friend ostream& operator<<(ostream& outs, const ShuntingYard& item)
    {
        outs<<item._profix;
        return outs;
    }

private:
    Queue<Token*> _profix;

};

#endif // SHUNTINGYARD_H
