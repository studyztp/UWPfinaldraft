#include "plot.h"

Plot::Plot()
{
    list_of_points.clear();
    infix.clear();
    profix.clear();
    ptr=nullptr;

    _error = 0;
    index = 0;
    gap = 0;
    _x = 0;
    _y=-99;
}
void Plot::set_info(Graph_info *info)
{
    _info = info;
}

vector<sf::Vector2f> Plot::get_list_pointer()
{
    list_of_points.clear();
    _x =0;
    if(_info->is_polar())
    {
        domain = 0;
        gap = (2*M_PI)/_info->get_Point_amount();
    }
    else
    {
        domain = _info->get_Domain_min();
        gap = _info->get_Domain_gap();
    }
    index = 0;
    _error = 0;
    infix.clear();
    profix.clear();                                         //make sure they are initialized
    ptr=nullptr;
    infix = tokenizer.infix(_info->get_input(),_error);     //get infix from tokenizer

    if(!_error)                                             //if tokenizer returns error then return an empty list to send a error message
    {
        profix = sy.profixing(infix);                       //else get profix from sy
        while(index != _info->get_Point_amount())
        {
            _error = rpn.calculating_y(profix,domain);           //if calculation got error
            _y = rpn.get_y();
            if(!_error)                                     //if it does not
            {
                if(_info->is_polar())
                {
                    _x = _y*(cos(domain));
                    _y *= (sin(domain));
                }
                else
                {
                    _x = domain;
                }
                _point = coord.trans(_x,_y,_info);
                if(_point != sf::Vector2f(-1,-1))
                    list_of_points.push_back(_point);//push translated point to list
            }

            index++;
            domain+=gap;

        }
        while(!infix.empty())                           //delete all dynamic variables
        {
            ptr = infix.pop();
            delete [] ptr;
        }
        rpn.clear();                                    //clear rpn dynmaic variables
    }
    else
    {
        cout<<"Tokenizer detected error"<<endl;
    }
    return list_of_points;                              //return list
}
bool Plot:: is_error() const
{
    return _error;
}
double Plot::get_y() const
{
    return _y;
}
