#ifndef SIDEBAR_H
#define SIDEBAR_H
#include "graph_info.h"
#include "NUMBERS.h"

const int FEATRUE_BUTTOM= 3;
class Sidebar
{
public:
    Sidebar();
    ~Sidebar();
                                                                        //most crowed class
    void set_info(Graph_info* info);
    void update(sf::Font& font);
    void update_current(sf::Font& font);
    void update_his_help_button();
    void update_curr_help_button();
    void draw(sf::RenderWindow& window);
    void history_update(sf::Font& font);
    int scroll_history(const int scroll);
    bool if_clicked_history(const int& mouseX, const int &mouseY);
    bool if_clicked_delete_history(const int& mouseX, const int &mouseY);
    int if_clicked_his_button(const int& mouseX, const int &mouseY);
    bool if_scroll_on_history(const int& mouseX, const int& mouseY);
    int if_clicked_curr_button(const int& mouseX, const int& mouseY);
    bool if_show_help(const int& mouseX, const int& mouseY);

private:
    Graph_info* _info;
    sf::RectangleShape current_bar;
    sf::Text current_address_text;
    sf::Vector2f current_location, current_size;
    sf::Sprite* history_bar;
    sf::Vector2f history_location,history_size,his_box_size,his_box_loc,his_text_loc;
    sf::RectangleShape* history_box;
    sf::Text* history_address;
    sf::Texture crosssign;
    sf::Sprite* cross_sprite;
    vector<string> history;
    sf::Texture auto_texture,auto_,auto_false,save,clear,historybar;
    sf::Text* button_help;
    sf::Sprite* history_button;
    sf::Texture enter,recenter,up,down,left,right,zoomin,zoomout,help_button,helpb_on,helpb_off;
    sf::Sprite* current_button;

    bool auto_on,help_on;
    int help_index;
//    sf::Vector2f his_butt_loc, his_butt_size;
//    sf::Color _his_zero_color, _yes, _no;

    int scrolled;

};

#endif // SIDEBAR_H
