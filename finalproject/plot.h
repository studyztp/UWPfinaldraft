#ifndef PLOT_H
#define PLOT_H
#include "coord_trans.h"
#include "rpn.h"
#include "tokenizer.h"

class Plot
{
public:
    Plot();
    void set_info(Graph_info* info);        //pass dynamic info
    vector<sf::Vector2f> get_list_pointer();//do calculation and return list
    double get_y() const;                   //return y
    bool is_error() const;

private:
    Graph_info* _info;
    Queue<Token*> infix;
    Coord_trans coord;
    Queue<Token*> profix;
    vector<sf::Vector2f> list_of_points;
    Tokenizer tokenizer;
    ShuntingYard sy;
    sf::Vector2f _point;
    RPN rpn;
    Token* ptr;
    double _y,_x;
    int _error;
    double  domain;
    double gap;
    int index;
};

#endif // PLOT_H
