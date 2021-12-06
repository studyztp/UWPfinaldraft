#include "rpn.h"

int RPN::calculating_y(const Queue<Token *> &profix, const double &domain)
{

    Queue<Token*> _profix(profix);
    Stack<Token*> temp;
    theX* xptr;
    Token* ptr;
    double a, b,ans;
    while(!_profix.empty())
    {
        ptr = _profix.pop();


        switch (ptr->get_type()) {
        case NUMBER:                    //if its number type
            {

            if(ptr->get_prec()==heyX)   //check if its x
            {
                xptr = static_cast<theX*>(ptr);
                if(xptr->if_negative())         //then check for negative
                {
                    a = domain*(-1);
                }
                else
                {
                    a = domain;
                }
                ptr = new Number(a);          //create a new dynamice Number
                address_book.push(ptr);       //store it to the address book for later detelet

            }
            temp.push(ptr);                     //push it in Stack
            if(!_profix.empty())                //if profix not empty
            {
            while(_profix[0]->get_type()==NUMBER&& !_profix.empty())//if there is still number members
            {
                ptr=_profix.pop();
                if(ptr->get_prec()==heyX)         //repeat the upper process as a loop
                {
                    xptr = static_cast<theX*>(ptr);
                    if(xptr->if_negative())
                    {
                        a = domain*(-1);
                    }
                    else
                    {
                        a = domain;
                    }
                    ptr = new Number(a);
                    address_book.push(ptr);
                }
                temp.push(ptr);

            }
            }


            break;
            }

        case OPERATOR:                      //if it's operator
        {
            Operator* op = static_cast<Operator*>(ptr);
            if(temp.empty())                //if number stack is empty
                return 1;                   //return error code 1 if it is
            else
                ptr=temp.pop();             //else pop it out
            b = static_cast<Number*>(ptr)->get_value();//get the value
            if(op->get_prec()==1&& temp.empty())        //if it;s "+" or "-"
            {
                ans = op->calculation(0,b);//do the calculation as -b or +b

            }
            else                                //if its empty and op not + or -
            {
            if(temp.empty())
                return 1;                       //error code 1
            else
                ptr = temp.pop();

            a = static_cast<Number*>(ptr)->get_value(); //return error as true when 1/0

            if(op->is_div()&&b==0)              //prevent 1/0
            {
                while(!_profix.empty())
                {
                    ptr = _profix.pop();
                }
                while(!temp.empty())
                {
                    ptr= temp.pop();
                }
                return 1;                       //error code
            }
            ans = op->calculation(a,b);
            }
            ans_ptr = new Number(1);
            address_book.push(ans_ptr);         //for later delete
            *ans_ptr=ans;
            temp.push(ans_ptr);
            break;
        }
        case FUNCTION:                          //if its function
        {
            Function* fun = static_cast<Function*>(ptr);
            if(temp.empty())
                return 1;
            else
                ptr = temp.pop();
            a = static_cast<Number*>(ptr)->get_value();
            ans = fun->calculation(a);
            if(fun->is_error())                 //check if calculation got wrong in function
                return 1;                       //return errror if so
            ans_ptr = new Number(1);            //or get a new dyanimic number for the ans
            address_book.push(ans_ptr);         //make sure store it
            *ans_ptr = ans;
            temp.push(ans_ptr);
            break;
        }
        default:
            break;

        }


    }

    ptr = temp.pop();
    _y = static_cast<Number*>(ptr)->get_value();
    if(!temp.empty())                           //if there are still number in stack
        return 1;                               //error code

    return 0;                                   //else return 0 as fine
}
void RPN::clear()
{
    Token* ptr;
    while(!address_book.empty())                //delete all created dynamic variables
    {
        ptr= address_book.pop();
        delete [] ptr;
    }
}

