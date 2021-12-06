#include "background.h"

Background::Background()
{
    draw_y = false;                                 //initialize
    draw_x = false;
}
Background::Background(Graph_info* info)
{
    draw_y = false;
    draw_x = false;
    _info = info;
}
void Background::set_info(Graph_info *info)
{
    _info = info;                                   //pass address
}
void Background::update()
{
    update_graph_background();                      //as name
    update_sb_background();
    update_xy();
/*
 * Note:
 * 06/03/2020
 * I tried to draw both x and y line combinaly at first, but it doesnt work well
 * after I implemented pan up and down, so now I separated them.
 * _y_line for x = 0 and _x_line for y = 0
 * works well so far
 * something worth to notice. I was experiencing tiny aligin problem before separting them,
 * but now it's gone.
 * I thought the aligin was cause by graph class, but it was actually caused by the line
*/

}
void Background::update_xy()
{
    if(_info->y_exist())                                    //if line y=0 is on the screen
    {
        draw_x = true;
        for(int index = 0; index < GRAPH_WIDTH; index ++)
        {
            _x_line[index].setPosition(index,_info->get_theCenter_y());
            _x_line[index].setFillColor(sf::Color::Black);
            _x_line[index].setRadius(0.5);
        }
    }
    if(_info->x_exist())                                //if line x = 0 is on the screen
    {
        draw_y = true;
        for(int index = 0; index <GRAPH_HEIGHT; index++)
        {
            _y_line[index].setPosition(_info->get_theCenter_x(),index);
            _y_line[index].setFillColor(sf::Color::Black);
            _y_line[index].setRadius(0.5);

        }
    }
}
void Background:: update_graph_background()
{
    graph_background.setSize(sf::Vector2f(GRAPH_WIDTH,GRAPH_HEIGHT));
    graph_background.setPosition(sf::Vector2f(0,0));
    graph_background.setFillColor(sf::Color(211,229,214));
}
void Background::update_sb_background()
{
    sb_background.setSize(sf::Vector2f(SCREEN_WIDTH-GRAPH_WIDTH,GRAPH_HEIGHT));
    sb_background.setPosition(GRAPH_WIDTH,0);
    sb_background.setFillColor(sf::Color(81, 108, 126));
}
void Background:: draw(sf::RenderWindow &window)
{
    window.draw(graph_background);
    window.draw(sb_background);

    if(draw_x)
    {
        for(int index = 0; index<GRAPH_WIDTH; index++)
        {
            window.draw(_x_line[index]);
        }
        draw_x = false;
    }
    if(draw_y)
    {
        for(int index = 0; index <GRAPH_HEIGHT; index++)
        {
            window.draw(_y_line[index]);
        }
        draw_y = false;
    }

}

