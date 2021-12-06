#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "graph_info.h"

class Background
{
public:
    Background();                           //default
    Background(Graph_info* info);           //one arg
    void set_info(Graph_info* info);        //pass dynamic info
    void update();
    void update_xy();                       //update xy line
    void update_graph_background();         //bg for graph
    void update_sb_background();            //bg for sb
    void draw(sf::RenderWindow& window);

private:
    sf::CircleShape _y_line[GRAPH_HEIGHT];
    sf::CircleShape _x_line[GRAPH_WIDTH];
    sf::RectangleShape graph_background;
    sf::RectangleShape sb_background;

    bool draw_y, draw_x;

    Graph_info *_info;
};

#endif // BACKGROUND_H
