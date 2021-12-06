#ifndef POP_UP_H
#define POP_UP_H
#include "graph_info.h"
class Pop_up
{
public:
    Pop_up();
    void set_info(Graph_info* info);
    void update();
    void draw(sf::RenderWindow& window);
    void set_warning(bool is_error)
    {
        warning = is_error;
    };
    double get_ib_x()
    {
        return ib_dis_x;
    }
    double get_ib_y()
    {
        return ib_dis_y;
    }
    double get_ib_height() const
    {
        return ib_height;
    }

private:
    double ob_dis_x,ob_dis_y,ob_height,ob_width,ib_dis_x,ib_dis_y,ib_height,ib_width;
    sf::Color ob_color, ib_color;
    sf::Texture warning_texture;
    sf::Sprite warning_sprite;
    sf::RectangleShape ob, ib;
    bool warning;

    Graph_info* _info;

};

#endif // POP_UP_H
