#ifndef TOKENIZER_H
#define TOKENIZER_H
/*
 * Note:
 * 06/03/2020
 * tokenizer for dummies :)
*/
#include "features.h"
#include <cstring>
#include <math.h>
#include <ctype.h>

const int SYMBOL_AMOUNT = 2;
const int FUNCTION_AMOUNT = 37;
class Tokenizer
{
public:
    Tokenizer();
    Queue<Token*> infix(const string& input, int& error);
    bool find_in_str(Queue<char>&input, const string& item);
    bool find_number(Queue<char>&input, double& theNumber);
    bool checkforerror(const string& input);
    void deleteallspace(Queue<char>&input);
    string deleteallspace(const string &input);
    string symbol[SYMBOL_AMOUNT]={"PI","E"};
    string function[FUNCTION_AMOUNT]= {"exp","ceil","floor","round","abs",
                                        "sqrt","cbrt","log10","log","ln","sign","gamma","lgamma",
                                       "sinh","cosh","csch","sech","tanh","coth",
                                       "asinh","atanh","acosh","acsch","asech","acoth",
                                       "asin","acos","atan","asec","acsc","acot",
                                      "cos","tan","sin","sec","csc","cot"};

private:
    char *_item;


};

#endif // TOKENIZER_H
