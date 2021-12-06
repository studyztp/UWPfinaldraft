#include "coord_trans.h"

Coord_trans::Coord_trans()
{
}
sf::Vector2f Coord_trans:: trans(const double& x, const double& y, Graph_info* info)
{
    double scale = double(GRAPH_WIDTH)/double(info->get_Domain_sum());//pixel per number between max and min

    point.x = (x-info->get_Domain_min())*scale;           //min*scale get the pixel of min, x minus it can get the screen coord of x
    point.y = (info->get_theCenter_y()-y*scale);          //y*scale get the pixel of y, center minus it can get the screen coord of y
    if(point.x> GRAPH_WIDTH||point.x<0)
        return sf::Vector2f(-1,-1);
    return point;                                       //return point
}
