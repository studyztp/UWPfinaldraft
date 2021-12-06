#ifndef FUNCTION_H
#define FUNCTION_H
#include "operator.h"'

class Function: public Operator
{
public:
    Function();
    Function(const string& item);
    int get_prec() const;                   //a high number such as 300
    int get_type() const;                   //return FUNCTION
    double calculation (const double& a);   //return an ans with a
    bool is_error()const;                   //if calculation got in error such as 1/0 then return true
    friend ostream& operator<<(ostream& outs, const Function& item)
    {
        outs<< item._value;
        return outs;
    }
private:
    string _value;
    bool _error;

};

#endif // FUNCTION_H
