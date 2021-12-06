#include "graph_info.h"

Graph_info::Graph_info()
{
    history.clear();
    theCenter.x = GRAPH_WIDTH/2;
    theCenter.y = GRAPH_HEIGHT/2;
    _Domain_min = -5;
    _Domain_max = 5;
    polar = false;
    _Point_amount = 5000;

  //  exceed_screen = false;

    load_history();                             //domain can be change in here
    if(!history.empty())
    {

        input = history[history.size()-1];     //if does have history then input = history graph
        history.pop_back();

    }
    else
    {
        input = "tan(1/x)";                     //else default as tan(1/x)
    }
    _Domain_sum = _Domain_max-_Domain_min;
    _Domain_gap = _Domain_sum/double(_Point_amount);
    _error = false;

}
void Graph_info::write_history_to_file()
{
    save_file.open("history.txt");
    if(!history.empty())
    {
        if(save_file.fail())
        {
            cout<<"Fail to open 'history.txt'"<<endl;
            exit(1);
        }
        for(int index = 0; index <history.size(); index++)                  //save histroy vector to txt
        {
            save_file<<history[index]<<'\n';
        }
        if(history[history.size()-1]!=input)
            save_file<<input<<'\n';
        save_file.clear();
        save_file.close();

    save_file.open("data.txt");
    if(save_file.fail())
    {
        cout<<"Fail to open 'data.txt'"<<endl;
        exit(1);
    }
    save_file<<"Min"<<'\n'<<_Domain_min<<'\n'<<"Max"<<'\n'<<_Domain_max<<'\n';//write in domain data
    save_file.clear();
    save_file.close();
    }
    else
    {
        save_file.close();
        reset_file();
    }
}
void Graph_info::change_domin(const double& min, const double& max)
{
    _Domain_min = min;
    _Domain_max = max;
    _Domain_sum = _Domain_max-_Domain_min;
    _Domain_gap = _Domain_sum/double(_Point_amount);
}
void Graph_info:: change_center(const sf::Vector2f newCenter)
{

//    if(newCenter.x >= 0 && newCenter.x <= GRAPH_WIDTH)
//    {
//        exceed_screen = false;
//    }
//    else
//        exceed_screen = true;

    theCenter.x = newCenter.x;
    theCenter.y = newCenter.y;

}
void Graph_info::save_history(const string &equation)
{
    if(!check_exist_in_his(equation))
        history.push_back(equation);
}
void Graph_info::load_history()
{
    in_file.open("history.txt");
    if(in_file.fail())
    {
        cout<<"Fail to open 'history.txt'"<<endl;
        exit(1);
    }
    string item;
    if(!if_file_empty(in_file))
    {
        in_file>>item;
        while(!in_file.eof())
        {
            history.push_back(item);
            in_file>>item;

        }
    }
    in_file.clear();
    in_file.close();
    in_file.open("data.txt");
    if(in_file.fail())
    {
        cout<<"Fail to open 'history.txt'"<<endl;
        exit(1);
    }
    double domain;
    if(!if_file_empty(in_file))
    {
        while(!in_file.eof())
        {
            in_file>>item;
            if(item=="Min")
            {
                in_file>>domain;
                _Domain_min = domain;
            }
            if(item=="Max")
            {
                in_file>>domain;
                _Domain_max = domain;
            }

        }

    }
    in_file.clear();
    in_file.close();
}
bool Graph_info:: if_file_empty(ifstream& file) const
{
    if(file.peek()==ifstream::traits_type::eof())           //if empty
    {
        return true;
    }
    return false;
}
void Graph_info::reset_histroy()
{

    history.clear();
}
void Graph_info::reset_file()
{
    save_file.open("data.txt");
    if(save_file.fail())
    {
        cout<<"Fail to open 'data.txt'"<<endl;
        exit(1);
    }
    save_file.close();
    history.clear();
    cout<<"reseted data file"<<endl;
        save_file.open("history.txt");
        if(save_file.fail())
        {
            cout<<"Fail to open 'history.txt'"<<endl;           //error message
            exit(1);
        }
        save_file.close();
    cout<<"reseted history file"<<endl;

}
void Graph_info::change_input(const string new_input)
{
    input = new_input;
}
bool Graph_info::y_exist() const
{
    if(theCenter.y>=0&&theCenter.y<=GRAPH_HEIGHT)
        return true;
    return false;
}
bool Graph_info::center_exist() const
{
    if(y_exist())
    {
        if(x_exist())
            return true;
    }
    return false;
}
bool Graph_info::x_exist() const
{
    if(_Domain_max>=0 && _Domain_min <= 0)
    {
            return true;
    }

    return false;
}
string Graph_info:: get_input()const
{
    return input;
}
void Graph_info::set_error(bool error)
{
    _error = error;
}
bool Graph_info::is_error() const
{
    return _error;
}
double Graph_info:: get_Domain_min()const
{
    return _Domain_min;
}
double Graph_info::get_Domain_max()const
{
    return _Domain_max;
}
double Graph_info::get_Domain_gap()const
{
    return _Domain_gap;
}
double Graph_info::get_Domain_sum()const
{
    return _Domain_sum;
}
double Graph_info::get_theCenter_x()const
{
    return theCenter.x;
}
double Graph_info::get_theCenter_y()const
{
    return theCenter.y;
}
vector<string> Graph_info::get_history() const
{
    return history;
}
bool Graph_info:: check_exist_in_his(const string& equation) const
{
    for(int index = 0; index < history.size(); index++)
    {
        if(history[index]==equation)
            return true;
    }
    return false;
}
void Graph_info:: delete_history(const int index)
{

    history.erase(history.begin()+index);
    cout<<"erase history ["<<index<<"] sucessfully"<<endl;
}
bool Graph_info::is_polar()const
{
    return polar;
}
void Graph_info:: set_polar(bool ifpolar)
{
    polar = ifpolar;
}
int Graph_info:: get_Point_amount() const
{
    return _Point_amount;
}
void Graph_info::add_Point_amount()
{
    if(_Point_amount<=20000)
        _Point_amount+=2500;
    _Domain_gap = _Domain_sum/double(_Point_amount);

}
void Graph_info::minus_Point_amount()
{
    if(_Point_amount>=5000)
        _Point_amount-=2500;
    _Domain_gap = _Domain_sum/double(_Point_amount);

}
