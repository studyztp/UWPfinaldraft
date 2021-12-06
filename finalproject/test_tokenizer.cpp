#include "test_tokenizer.h"

void test_tokenizer()
{
    Tokenizer test;
    int error = 0;
    Queue<Token*> result;
    Token* ptr;
    string teststring = "(e^x-e^(-x))/2";

    result = test.infix(teststring,error);

    if(error)
        cout<<"error";
    else
    {

        for(int i = 0; i<11;i ++)
        {
            ptr = result[i];
            switch (ptr->get_type()) {
            case NUMBER:
                if(ptr->get_prec()==heyX)
                {
                    cout<<*(static_cast<theX*>(ptr));
                }
                else
                {
                    cout<<*(static_cast<Number*>(ptr));
                }
                break;
            case OPERATOR:
                cout<<*(static_cast<Operator*>(ptr));
                break;
            case FUNCTION:
                cout<<*(static_cast<Function*>(ptr));
            default:
                break;

            }
            cout<<"||";

        }
    }
    cout<<endl;
    ShuntingYard sy;
    Queue<Token*> profix;
    profix = sy.profixing(result);
    for(int i = 0; i<9;i ++)
    {
        ptr = profix[i];
        switch (ptr->get_type()) {
        case NUMBER:
            if(ptr->get_prec()==heyX)
            {
                cout<<*(static_cast<theX*>(ptr));
            }
            else
            {
                cout<<*(static_cast<Number*>(ptr));
            }
            break;
        case OPERATOR:
            cout<<*(static_cast<Operator*>(ptr));
            break;
        case FUNCTION:
            cout<<*(static_cast<Function*>(ptr));
        default:
            break;

        }
        cout<<"||";

    }
    RPN rpn;
    rpn.calculating_y(profix,1);
    cout<<"ans:"<<rpn.get_y();
}
