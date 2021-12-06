#include "shuntingyard.h"

ShuntingYard::ShuntingYard()
{

}

Queue<Token*> ShuntingYard::profixing(const Queue<Token*>& in)
{
    _profix.clear();                    //make sure empty
    Queue<Token*>infix(in);
    Token* ptr;
    bool left = false;
    Stack<Token*> temp;
    while(!infix.empty())
    {
        ptr = infix.pop();

        switch (ptr->get_type()) {
        case NUMBER:
            _profix.push(ptr);

            break;
        case OPERATOR:
            if(temp.empty()||temp[0]->get_type()==LeftP)
                temp.push(ptr);
            else
            {
                if(left)                    //if ( exist
                {

                    if(ptr->get_prec()<=temp[0]->get_prec())
                    {
                        _profix.push(temp.pop());
                        while(!temp.empty())
                        {
                            if(ptr->get_prec()<=temp[0]->get_prec()&&temp[0]->get_type()!=LeftP)//not crossing (
                            {
                                _profix.push(temp.pop());
                            }
                            else
                                break;
                        }
                    }
                    temp.push(ptr);
                }
                else                                                //if ( does not exist
                {
                    if(ptr->get_prec()<=temp[0]->get_prec())        //check the bigger of prec
                    {
                        _profix.push(temp.pop());                   //push the big out if small sits on it
                        while(!temp.empty())
                        {
                            if(ptr->get_prec()<=temp[0]->get_prec()&& !temp.empty())
                                _profix.push(temp.pop());
                            else
                                break;
                        }
                    }
                    temp.push(ptr);
                }
            }
            break;
        case FUNCTION:
            temp.push(ptr);
            break;
        case LeftP:
            temp.push(ptr);
            left = true;
            break;
        case RightP:
            left = false;
            ptr = temp.pop();
            while(ptr->get_type()!= LeftP)
            {
                _profix.push(ptr);
                ptr=temp.pop();
            }
            break;
        default:
            break;
        }


    }
    while(!temp.empty())
    {
        _profix.push(temp.pop());
    }
    return _profix;

}
