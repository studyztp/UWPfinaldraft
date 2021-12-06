#ifndef COORD_TRANS_H
#define COORD_TRANS_H
#include "graph_info.h"

struct Coord_trans
{
    Coord_trans();                  //default
    sf::Vector2f point;             //temp point(x,y)
    sf::Vector2f trans(const double& x, const double& y, Graph_info* info);

};

#endif // COORD_TRANS_H
