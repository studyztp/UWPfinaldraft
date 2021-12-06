#include "function.h"

Function::Function()
{
    _value = "";
    _error = false;
}
Function::Function(const string& item)
{
    _value = item;
}
int Function::get_prec() const
{
    return 300;
}
int Function::get_type() const
{
    return FUNCTION;
}
bool Function:: is_error() const
{
    return _error;
}
double Function::calculation (const double& a)
{
    _error = false;

    //trig
    if(_value == "cos")
        return (cos(a));
    if(_value == "sin")
        return (sin(a));
    if(_value == "tan")
        return (tan(a));
    if(_value == "sec")
    {
        if(cos(a)==0)
        {
            _error = true;
            return 0;
        }
        return (1/cos(a));
    }
    if(_value == "csc")
    {
        if(sin(a)==0)
        {
            _error = true;
            return 0;
        }
        return (1/sin(a));
    }
    if(_value == "cot")
    {
        if(tan(a)==0)
        {
            _error = true;
            return 0;
        }
        return (1/tan(a));
    }
    //hypobolic
    if(_value == "sinh")
        return (sinh(a));
    if(_value == "cosh")
        return (cosh(a));
    if(_value == "tanh")
        return (tanh(a));
    if(_value == "sech")
    {
        if(cosh(a)== 0)
        {
            _error = true;
            return 0;
        }
        return (1/cosh(a));
    }
    if(_value == "csch")
    {
        if(sinh(a)==0)
        {
            _error = true;
            return 0;
        }
        return (1/sinh(a));
    }
    if(_value =="coth")
    {
        if(tanh(a)==0)
        {
            _error = true;
            return 0;
        }
        return (1/tanh(a));
    }

    //inverse trig
    if(_value == "asin")
    {
        return asin(a);
    }
    if(_value == "acos")
    {
        return acos(a);
    }
    if(_value == "atan")
    {
        return atan(a);
    }
    if(_value == "asec")
    {
        if(a==0)
        {
            _error = true;
            return 0;
        }
        return (acos(1/a));
    }
    if(_value == "acsc")
    {
        if(a ==0)
        {
            _error = true;
            return 0;
        }
        return (asin(1/a));
    }
    if(_value == "acot")
    {
        if(a==0)
        {
            _error = true;
            return  0;
        }
        return (atan(1/a));
    }
    //inverse hypobolic
    if(_value == "asinh")
        return asinh(a);
    if(_value == "atanh")
    {
        return atanh(a);
    }
    if(_value == "acosh")
    {
        return acosh(a);
    }
    if(_value == "asech")
    {
        if(a==0)
        {
            _error = true;
            return 0;
        }
        return acosh(1/a);
    }
    if(_value == "acsch")
    {
        if(a==0)
        {
            _error = true;
            return 0;
        }
        return asinh(1/a);
    }
    if(_value == "acoth")
    {
        if(a==0)
        {
            _error = true;
            return 0;
        }
        return atanh(1/a);
    }



    if(_value == "gamma")
        return (tgamma(a));//gamma
    if(_value == "lgamma")
        return (lgamma(a));//log gamma
    if(_value == "sqrt")
        return (sqrt(a));
    if(_value == "cbrt")
        return (cbrt(a));
    if(_value == "log"||_value == "ln")
    {
        return log(a);
    }
    if(_value == "log10")
    {
        return log10(a);
    }
    if(_value == "sign")
    {
        return (a/abs(a));
    }
    if(_value == "exp")
    {
        return exp(a);
    }
    if(_value == "ceil")
        return ceil(a);
    if(_value == "floor")
        return floor(a);
    if(_value == "round")
        return round(a);
    if(_value == "abs")
        return abs(a);









}
