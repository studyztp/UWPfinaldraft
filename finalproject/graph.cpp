#include "graph.h"

Graph::Graph()
{
    point_color = sf::Color(44,89,120);      //initalize
    line_color = sf::Color(74, 180, 75 );
    line = nullptr;
    _circle = nullptr;
    temp = _circle;
    size = 0;

}
Graph::Graph(Graph_info* info)
{
    point_color = sf::Color(44,89,120);      //initalize
    line_color = sf::Color(74, 180, 75 );
    line = nullptr;
    _circle = nullptr;
    temp = _circle;
    size = 0;
    _info = info;
    _plot.set_info(info);
}
void Graph::set_info(Graph_info *info)
{
    _info = info;
    _plot.set_info(info);
}
Graph::~Graph()
{
  //make sure the last one is deleted here
    delete [] temp;
    delete line;

}
void Graph::updatewpoint()
{
    list_of_points.clear();
    list_of_points = _plot.get_list_pointer();
    if(list_of_points.empty())                                  //if list is empty
    {
        _info->set_error(true);                                 //return error to upper class
        cout<<"rpn.calculation error"<<endl;
    }
    else
    {

        _info->set_error(false);                              //cancel error sign
        delete [] temp;
        _circle = new sf::CircleShape[list_of_points.size()];//use dynamic array because of personal interest
                                                             //and prevent drawing unnessaary points
        temp = _circle;                                      //save address for delete and another rw purpse

        size = list_of_points.size();                       //save size in case of draw graph after clear list
        for(int index = 0; index < size; index ++)
        {
            _circle->setRadius(1.25);
            _circle->setFillColor(point_color);
            _circle->setPosition(list_of_points[index]);
            _circle++;

        }
        _circle = temp;
    }
}
void Graph::updatewline()
{
    list_of_points.clear();
    list_of_points = _plot.get_list_pointer();
    if(list_of_points.empty())                                  //if list is empty
    {
        _info->set_error(true);                                 //return error to upper class
        cout<<"rpn.calculation error"<<endl;
    }
    else
    {
        size = list_of_points.size();

        _info->set_error(false);                              //cancel error sign
        delete  line;
        line = new sf::VertexArray(sf::LinesStrip,size);//use dynamic array because of personal interest
                                                             //and prevent drawing unnessaary points
                                      //save address for delete and another rw purpse

                          //save size in case of draw graph after clear list
        for(int index = 0; index < size; index ++)
        {
            (*line)[index].color = line_color;
            (*line)[index].position = list_of_points[index];

        }

    }
}
void Graph:: drawwline(sf::RenderWindow &window)
{
        window.draw(*line);

}
void Graph::drawwpoint(sf::RenderWindow &window)
{

    _circle = temp;
    for(int index =0; index<size; index++)
    {
        window.draw(*_circle);
        _circle++;
    }
}
