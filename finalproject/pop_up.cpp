#include "pop_up.h"

Pop_up::Pop_up()
{
    ob_dis_x = GRAPH_WIDTH/10;
    ob_dis_y = GRAPH_HEIGHT/20;
    ob_height = GRAPH_HEIGHT/10;
    ob_width = 8*(GRAPH_WIDTH/10);
    ib_dis_x = (ob_dis_x/10)*15;
    ib_dis_y = ob_dis_y+8;
    ib_width = 9.25*(ob_width/10);
    ib_height = 8*(ob_height/10);
    ob_color = sf::Color(44,89,120);
    ib_color = sf::Color::White;
    warning = false;
    if(!warning_texture.loadFromFile("warning.jpg"))
    {
        cout<<"Fail to load 'warning.jpg'"<<endl;
        exit(1);
    }

    warning_sprite.setTexture(warning_texture);
}
void Pop_up::set_info(Graph_info *info)
{
    _info = info;
}
void Pop_up::update()
{

    ob.setSize(sf::Vector2f(ob_width,ob_height));             //outer box
    ob.setFillColor(ob_color);
    ob.setPosition(sf::Vector2f(ob_dis_x,ob_dis_y));

    ib.setSize(sf::Vector2f(ib_width,ib_height));             //inner box
    ib.setFillColor(ib_color);
    ib.setPosition(sf::Vector2f(ib_dis_x,ib_dis_y));

    if(warning)                                                 //if warnnign is on
    {
        warning_sprite.setTexture(warning_texture);          //warning sign
        warning_sprite.setPosition(ib_dis_x+ib_width-50,ib_dis_y+15);
    }


}
void Pop_up::draw(sf::RenderWindow &window)
{
    window.draw(ob);
    window.draw(ib);
    if(warning)
    {
        window.draw(warning_sprite);
    }
}
