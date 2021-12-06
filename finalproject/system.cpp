#include "system.h"

System::System()
{
    _change = true;
}
System::System(Graph_info* info)
{
    _info = info;
    graph.set_info(info);
    bg.set_info(info);
    _change = true;
    line = false;
    point = true;
}
void System::set_info(Graph_info *info)
{
    _info = info;
    graph.set_info(info);
    bg.set_info(info);
    line = false;
    point = true;
}
void System:: update()
{
    if(_change)
    {
        _change = false;
        if(point)
            graph.updatewpoint();
        if(line)
            graph.updatewline();
    }
    bg.update();
}
void System:: draw(sf::RenderWindow& window)
{
    bg.draw(window);
    if(point)
        graph.drawwpoint(window);
    if(line)
        graph.drawwline(window);
}

int System::step(const int command)
{
    if(command)
        _change =true;
    switch (command) {
    case ENTER:
        return 0;
    case ZOOMIN:
        zoom_in();
        return 0;
    case ZOOMOUT:
        zoom_out();
        return 0;
    case PANUP:
        pan_up();
        return 0;
    case PANDOWN:
        pan_down();
        return 0;
    case PANLEFT:
        pan_left();
        return 0;
    case PANRIGHT:
        pan_right();
        return 0;
    case RECENTER:
        recenter();
        return 0;
    case POLAR_ON:
        recenter();
        _info->set_polar(true);
        return 0;
    case POLAR_OFF:
        _info->set_polar(false);
        return 0;
    case ADD_POINT_AMOUNT:
        _info->add_Point_amount();
        return 0;
    case MINUS_POINT_AMOUNT:
        _info->minus_Point_amount();
        return 0;
    case TURN_ON_LINE:
        line = true;
        return 0;
    case TURN_OFF_LINE:
        line = false;
        return 0;
    case TURN_ON_POINT:
        point = true;
        return 0;
    case TURN_OFF_POINT:
        point = false;
        return 0;
    default:
        return 0;

    }
}

void System::recenter()
{
    _info->change_center(sf::Vector2f(GRAPH_WIDTH/2,GRAPH_HEIGHT/2));
    _info->change_domin(-5,5);
}
void System:: zoom_in()
{
    double min =_info->get_Domain_min()+(_info->get_Domain_sum()/double(DOMAIN_AMOUNT));
    double max = _info->get_Domain_max()-(_info->get_Domain_sum()/double(DOMAIN_AMOUNT));
    _info->change_domin(min,max);
    locate_center_x();
}
void System:: zoom_out()
{
    double min =_info->get_Domain_min()-(_info->get_Domain_sum()/double(DOMAIN_AMOUNT));
    double max = _info->get_Domain_max()+(_info->get_Domain_sum()/double(DOMAIN_AMOUNT));
    _info->change_domin(min,max);
    locate_center_x();
}
void System::pan_left()
{
    double newx = _info->get_theCenter_x()+(double(GRAPH_WIDTH)/double(DOMAIN_AMOUNT));
    _info->change_domin(_info->get_Domain_min()-(_info->get_Domain_sum()/double(DOMAIN_AMOUNT)),_info->get_Domain_max()-(_info->get_Domain_sum()/double(DOMAIN_AMOUNT)));
    if(_info->x_exist())
    {
        _info->change_center(sf::Vector2f(newx,_info->get_theCenter_y()));
        locate_center_x();
    }
}
void System::pan_right()
{
    double newx = _info->get_theCenter_x()-(double(GRAPH_WIDTH)/double(DOMAIN_AMOUNT));
    _info->change_domin(_info->get_Domain_min()+(_info->get_Domain_sum()/double(DOMAIN_AMOUNT)),_info->get_Domain_max()+(_info->get_Domain_sum()/double(DOMAIN_AMOUNT)));
    if(_info->x_exist())
    {
        _info->change_center(sf::Vector2f(newx,_info->get_theCenter_y()));
        locate_center_x();
    }
}
void System::locate_center_x()
{
    double scale = double(GRAPH_WIDTH)/double(_info->get_Domain_sum());
    double location = 0;
    double x = _info->get_Domain_min();
    if(_info->x_exist())
    {
        location = abs(_info->get_Domain_min())*scale;
        _info->change_center(sf::Vector2f(location,_info->get_theCenter_y()));
    }
    else
    {
        _info->change_center(sf::Vector2f(-1,_info->get_theCenter_y()));
    }

}

void System:: pan_up()
{
    double newy = _info->get_theCenter_y()+(double(GRAPH_WIDTH)/double(DOMAIN_AMOUNT));
    _info->change_center(sf::Vector2f(_info->get_theCenter_x(),newy));
}
void System:: pan_down()
{
    double newy = _info->get_theCenter_y()-(double(GRAPH_WIDTH)/double(DOMAIN_AMOUNT));
    _info->change_center(sf::Vector2f(_info->get_theCenter_x(),newy));
}
bool System::check_for_input_error(const string& input)
{
    int error =0;
    tokenizer.infix(input,error);
    return error;
}
string System:: deleteallspace(const string& input)
{

    return tokenizer.deleteallspace(input);

}
