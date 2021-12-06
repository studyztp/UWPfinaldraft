#ifndef GRAPH_INFO_H
#define GRAPH_INFO_H
#include <iostream>
#include "SFML/Graphics.hpp"
#include <fstream>
using namespace std;
const int GRAPH_WIDTH = 800;
const int GRAPH_HEIGHT = 800;
const int DOMAIN_AMOUNT = 10;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 800;
const int SCREEN_RATE = 50;
class Graph_info
{
public:
    Graph_info();

    void change_domin(const double& min, const double& max);    //change domain
    void change_center(const sf::Vector2f newCenter);           //change center
    void change_input(const string new_input);                  //change input
    bool y_exist() const;                                       //if y=0 exits on the screen
    bool center_exist() const;                                  //if y= 0 and x = 0 exsit
    bool x_exist() const;                                       //if x = 0 exist
    string get_input() const;                                   //return input
    void set_error(bool error);                                 //set error
    bool is_error() const;                                      //return error status
    bool is_polar()const;
    void set_polar(bool ifpolar);
    void load_history();                                        //load history from file
    void save_history(const string& equation);                  //save history to vector
    void write_history_to_file();                               //write histroy to file
    void reset_histroy();                                       //clear all histroy
    void reset_file();
    bool check_exist_in_his(const string& equation) const;      //check if equation already exist in histroy vecctor
    double get_Domain_min()const;
    double get_Domain_max()const;
    double get_Domain_gap()const;
    double get_Domain_sum()const;
    double get_theCenter_x()const;
    double get_theCenter_y()const;
    bool if_file_empty(ifstream& file) const;                   //return true if its empty
    void delete_history(const int index);                       //delet history in given location
    vector<string> get_history()const;
    int get_Point_amount()const;
    void add_Point_amount();
    void minus_Point_amount();
private:
    double _Domain_min, _Domain_max, _Domain_gap,_Domain_sum;
    int _Point_amount;
    sf::Vector2f theCenter;
    string input ;
    bool _error, polar;
    ifstream in_file;
    ofstream save_file;
    vector<string> history;



 //   bool exceed_screen;
};

#endif // GRAPH_INFO_H
