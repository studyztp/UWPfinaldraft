#ifndef RPN_H
#define RPN_H
#include "shuntingyard.h"
#include "graph_info.h"
#include "math.h"
class RPN
{
public:
    RPN()
    {}
    int calculating_y(const Queue<Token*>& profix,const double &domain);//calculation return error code
    double get_y() const
    {
        return _y;
    }
    void clear();               //delete new created dynamic variable
private:
    double _y;
    Number* ans_ptr;
    Queue<Token*> address_book; //store new created dynamic variable
};

#endif // RPN_H
