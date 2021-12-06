#ifndef SYSTEM_H
#define SYSTEM_H
#include "graph.h"
#include "background.h"
#include "tokenizer.h"


class System
{
public:
    System();
    System(Graph_info* info);
    void set_info(Graph_info* info);
    int step(const int command);

    void draw_bg(sf::RenderWindow& window);
    void zoom_in();
    void zoom_out();
    void pan_up();
    void pan_down();
    void pan_left();
    void pan_right();
    void locate_center_x();
    void recenter();
    bool check_for_input_error(const string& input);
    string deleteallspace(const string& input);

    void update();
    void draw(sf::RenderWindow&window);

private:
    Graph graph;
    Graph_info* _info;
    Background bg;
    Tokenizer tokenizer;
    bool _change, line, point;

};

#endif // SYSTEM_H
