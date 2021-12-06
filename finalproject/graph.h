#ifndef GRAPH_H
#define GRAPH_H
#include "graph_info.h"
#include <SFML/Graphics/VertexArray.hpp>
#include "plot.h"
class Graph
{
public:
    Graph();
    Graph(Graph_info* info);
    void set_info(Graph_info* info);        //pass dynamic info
    void updatewpoint();
    void updatewline();
    void drawwline(sf::RenderWindow &window);
    void drawwpoint(sf::RenderWindow & window);

    ~Graph();                               //delete dynamic circleshape
private:
    double x;
    sf::Vector2f _point;
    sf::Color point_color, line_color;
    vector<sf::Vector2f>list_of_points;
    sf::CircleShape* _circle,*temp;
    sf::VertexArray *line;
    Graph_info* _info;
    int size;
/*
 * Note:
 * 6/04/2020
 * for draw with line
 * but doesnt work for small points such as sin(1/x)
*/
    Plot _plot;

};

#endif // GRAPH_H
