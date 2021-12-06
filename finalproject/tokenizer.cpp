#include "tokenizer.h"

Tokenizer::Tokenizer()
{
}
void Tokenizer::deleteallspace(Queue<char>&input)
{
    Queue<char> temp;
    while(!input.empty())
    {
        temp.push(input.pop());
    }
    input.clear();
    while(!temp.empty())
    {
        if(!isspace(temp[0]))
        {
            input.push(temp.pop());
        }
        else
        {
            temp.pop();
        }
    }
}
Queue<Token*> Tokenizer::infix(const string& input, int & error)
{
    Queue<Token*> finalToken;
    int counter =0 ;
    Queue<char> temp;
    bool possible_be_negative = true;
    string symbol[SYMBOL_AMOUNT]={"PI","E"};
    string theItem;
    double thenumber;
    bool found = false;
    for(int index = 0; index < input.length(); index++)
    {
        temp.push(input[index]);
    }
    //cout<<temp;
    deleteallspace(temp);
    while(!temp.empty())
    {


        for(int index = 0; index < FUNCTION_AMOUNT; index ++)
        {
            if(!found)
            {
            found = find_in_str(temp,function[index]);
            if(found)
            {
                possible_be_negative = true;
                finalToken.push(new Function(function[index]));
            }
            }
        }
        if(!found)
        {
            found = find_in_str(temp, "(");
            if(found)
            {
                possible_be_negative = true;
                finalToken.push(new LP());
            }
        }
        if(!found)
        {
            found =find_in_str(temp,")");
            if(found)
                finalToken.push(new RP());
        }
        if(!found)
        {
            found = find_in_str(temp,"+");
            if(found)
            {
                possible_be_negative = true;
                finalToken.push(new Operator ("+"));
            }
        }

        if(!found)
        {
            found = find_in_str(temp, "-");
            if(found)
            {
                if(possible_be_negative)
                {
                    found = find_number(temp,thenumber);
                    if(found)
                    {
                        finalToken.push(new Number(thenumber,true));
                    }
                    else
                    {
                        found = find_in_str(temp,"x");
                        if(found)
                        {
                            finalToken.push(new theX(true));//set up negative option for x
                        }
                        else
                        {
                            for(int index = 0; index < SYMBOL_AMOUNT; index ++)
                            {
                                if(!found)
                                {
                                found = find_in_str(temp,symbol[index]);
                                if(found)
                                {
                                    possible_be_negative = false;
                                    finalToken.push(new Number(symbol[index],true));
                                }
                                }
                            }
                        }
                    }
                    possible_be_negative = false;
                }
                else
                {
                    possible_be_negative = true;
                    finalToken.push(new Operator("-"));
                }
            }
        }
        if(!found)
        {
            found = find_in_str(temp,"*");
            if(found)
            {
                possible_be_negative = true;
                finalToken.push(new Operator("*"));
            }
        }
        if(!found)
        {
            found = find_in_str(temp, "/");
            if(found)
            {
                possible_be_negative = true;
                finalToken.push(new Operator("/"));
            }
        }
        if(!found)
        {
            found = find_in_str(temp,"^");
            if(found)
            {
                possible_be_negative = true;
                finalToken.push(new Operator("^"));
            }
        }
        if(!found)
        {
            found = find_in_str(temp,"pow");
            if(found)
            {
                possible_be_negative = true;
                finalToken.push(new Operator("^"));
            }
        }
        if(!found)
        {
            found = find_in_str(temp,"x");
            if(found)
            {
                possible_be_negative = false;
                finalToken.push(new theX(false));
            }
        }
        for(int index = 0; index < SYMBOL_AMOUNT; index ++)
        {
            if(!found)
            {
            found = find_in_str(temp,symbol[index]);
            if(found)
            {
                possible_be_negative = false;
                finalToken.push(new Number(symbol[index]));
            }
            }
        }
        if(!found)
        {
            found = find_number(temp,thenumber);
            if(found)
            {
                possible_be_negative = false;
                finalToken.push(new Number(thenumber));
            }
        }

        if(!found)
        {
            found = find_in_str(temp,"f(x)");//clear out these when found
            found = find_in_str(temp,"=");
        }
        counter ++;
        if(counter >= 100)//if this loop goes over 100 times still cant
                          //get out then there must be something wrong
                          //with the function
                          //then it returns an error
        {
            error= 1;
            break;
        }
        if(found)
            found = false;
    }
    if(finalToken.empty())
        error = 1;
    return finalToken;
}
bool Tokenizer::find_in_str(Queue<char>&input, const string& item)
{

    int letter_amount = item.length();
    string recorder;
    bool debug = false;
    int exist = 0;
    char src, find;

    for(int index = 0; index < letter_amount; index++)
    {
        src = input[index];
        find = item[index];
        if(isalpha(input[index])&&isalpha(item[index]))
        {
            src = toupper(src);
            find = toupper(find);
        }
        if(src==find)
        {
            exist++;
            recorder.push_back(src);
        }

    }
    if(debug)
    {
        cout<<recorder;
    }
    if(exist == letter_amount)
    {

        for(int index = 0; index < letter_amount; index++)
        {
            input.pop();
        }
        return true;
    }
    return false;
}
bool Tokenizer::find_number(Queue<char>&input, double& theNumber)
{

    if(isdigit(input[0]))
    {

        theNumber = 0;
        theNumber += int(input[0]-'0');
        bool decimal = false;
        double afterd;
        int index =0;
        input.pop();
        while(!input.empty())
        {
            if(isdigit(input[0]))
            {
                if(!decimal)
                {
                    theNumber*=10;
                    theNumber += int((input[0])-'0');
                    input.pop();
                }
                else
                {
                    afterd = int((input[0])-'0');

                    for(int i = 0; i <index; i++)
                    {
                        afterd*= 0.1;
                    }
                     index++;
                    theNumber+=afterd;
                    input.pop();
                }
            }
            else
            {
                if(input[0]=='.'&& !decimal)
                {
                    decimal = true;
                    index++;
                    input.pop();
                }
                else
                {
                    return true;
                }

            }
        }
        return true;
    }
    else
        return false;
}
bool Tokenizer::checkforerror(const string &input)
{
    int error =0;
    infix(input,error);
    if(error)
        return true;
    else
        return false;
}
string Tokenizer:: deleteallspace(const string& input)
{
    Queue<char> temp,temp2;
    string output;
    for(int index = 0; index <input.size(); index++)
    {
        temp.push(input[index]);
    }
    while(!temp.empty())
    {
        if(!isspace(temp[0]))
        {
            temp2.push(temp.pop());
        }
        else
        {
            temp.pop();
        }
    }
    while(!temp2.empty())
    {
        output.push_back(temp2.pop());
    }
    return output;
}
