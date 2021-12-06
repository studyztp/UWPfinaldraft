#include "sidebar.h"

Sidebar::Sidebar()
{


    if(!crosssign.loadFromFile("cross.jpg"))
    {
        cout<<"Fail to open 'cross.jpg'"<<endl;
        exit(1);
    }
    scrolled = 0;

    current_location =sf::Vector2f(GRAPH_WIDTH+15,GRAPH_HEIGHT/20+8);
    current_size = sf::Vector2f(SCREEN_WIDTH-GRAPH_WIDTH-30,(2*GRAPH_HEIGHT)/25);
    history_size = sf::Vector2f(current_size.x+18,3*(SCREEN_HEIGHT/5)-90);
    history_location =sf::Vector2f(current_location.x-9,GRAPH_HEIGHT/2);
    his_box_size = sf::Vector2f(current_size.x+12,((2*SCREEN_HEIGHT)/25)-10);
    his_box_loc =sf::Vector2f(history_location.x+3,history_location.y+20+his_box_size.y);
    his_text_loc = sf::Vector2f(history_location.x+5,history_location.y+30+his_box_size.y);

    cross_sprite = new sf::Sprite[5];                       //met bad_alloc during testing
    history_address = new sf::Text [5];                     //so found dynamic variable easier to manage
    history_box = new sf::RectangleShape[5];
    history_button = new sf::Sprite[3];
    current_button = new sf::Sprite[9];
    history_bar = new sf::Sprite;
    button_help = new sf:: Text[13];
    help_index = -1;
    help_on = false;

    if(!historybar.loadFromFile("history_bar.jpg"))
    {
        cout<<"Fail to open 'history_bar.jpg'"<<endl;
        exit(1);
    }
    if(!auto_.loadFromFile("autosave.jpg"))
    {
        cout<<"Fail to open 'autosave.jpg'"<<endl;
        exit(1);
    }
    if(!auto_false.loadFromFile("autosave_false.jpg"))
    {
        cout<<"Fail to open 'autosave_false.jpg'"<<endl;
        exit(1);
    }
    if(!save.loadFromFile("save.jpg"))
    {
        cout<<"Fail to open 'save.jpg'"<<endl;
        exit(1);
    }
    if(!clear.loadFromFile("clear.jpg"))
    {
        cout<<"Fail to open 'clear.jpg'"<<endl;
        exit(1);
    }
    auto_texture = auto_false;
    auto_on = false;

    if(!enter.loadFromFile("enter.jpg"))
    {
        cout<<"Fail to open 'enter.jpg'"<<endl;
        exit(1);
    }
    if(!recenter.loadFromFile("recenter.jpg"))
    {
        cout<<"Fail to open 'recenter.jpg'"<<endl;
        exit(1);
    }
    if(!up.loadFromFile("up.jpg"))
    {
        cout<<"Fail to open 'up.jpg'"<<endl;
        exit(1);
    }
    if(!down.loadFromFile("down.jpg"))
    {
        cout<<"Fail to open 'down.jpg'"<<endl;
        exit(1);
    }
    if(!left.loadFromFile("left.jpg"))
    {
        cout<<"Fail to open 'left.jpg'"<<endl;
        exit(1);
    }
    if(!right.loadFromFile("right.jpg"))
    {
        cout<<"Fail to open 'right.jpg'"<<endl;
        exit(1);
    }
    if(!zoomin.loadFromFile("in.jpg"))
    {
        cout<<"Fail to open 'in.jpg'"<<endl;
        exit(1);
    }
    if(!zoomout.loadFromFile("out.jpg"))
    {
        cout<<"Fail to open 'out.jpg'"<<endl;
        exit(1);
    }
    if(!helpb_on.loadFromFile("helpon.jpg"))
    {
        cout<<"Fail to open 'helpon.jpg'"<<endl;
        exit(1);
    }
    if(!helpb_off.loadFromFile("helpoff.jpg"))
    {
        cout<<"Fail to open 'helpoff.jpg'"<<endl;
        exit(1);
    }
    help_button = helpb_off;

}
Sidebar::~Sidebar()
{
    delete [] cross_sprite;
    delete [] history_address;
    delete [] history_box;
    delete [] history_button;
    delete [] history_bar;
    delete [] button_help;
}
void Sidebar::set_info(Graph_info *info)
{
    _info = info;
}
void Sidebar::update(sf::Font &font)
{
    update_current(font);
    history_update(font);
    update_his_help_button();
    update_curr_help_button();

}
void Sidebar::update_current(sf::Font &font)
{
    current_bar.setSize(current_size);
    current_bar.setPosition(current_location);
    current_bar.setFillColor(sf::Color::White);
    current_bar.setOutlineColor(sf::Color(44,89,120));
    current_bar.setOutlineThickness(9);
    button_help[12].setString("shift+Q/W to graph line/point \n shift + P to graph Polar \n shift + A/S to add/minus points");

    current_address_text.setFont(font);
    current_address_text.setFillColor(sf::Color::Black);
    current_address_text.setCharacterSize(25);
    current_address_text.setPosition(current_location.x+5,current_location.y+15);
    current_address_text.setString(_info->get_input());

    if(help_index!=-1)
    {

            button_help[help_index].setFont(font);
            button_help[help_index].setFillColor(sf::Color(8, 58, 0 ));
            button_help[help_index].setCharacterSize(18);
    }
}
void Sidebar::draw(sf::RenderWindow &window)
{
    for(int index = 0 ; index < 3; index ++)
    {
        window.draw(history_button[index]);

    }
    for(int index =0; index <9; index++)
    {
        window.draw(current_button[index]);
    }

    window.draw(current_bar);
    window.draw(current_address_text);
    window.draw(*history_bar);
    for(int index = 0; index<5; index++)
    {

        if((!history.empty())&&(history.size()-1)>=index)
        {
            window.draw(history_box[index]);
            window.draw(history_address[index]);
            window.draw(cross_sprite[index]);
        }

    }
    if(help_index!=-1)
    {

        window.draw(button_help[help_index]);

    }



//    window.draw(buttom);
}

void Sidebar:: update_his_help_button()
{
    history_button[0].setTexture(auto_texture);
    history_button[0].setPosition(GRAPH_WIDTH+10,GRAPH_HEIGHT/2-50);
    button_help[9].setString("press to turn off");

    history_button[1].setTexture(save);
    history_button[1].setPosition(GRAPH_WIDTH+20+auto_.getSize().x,GRAPH_HEIGHT/2-50);
    button_help[10].setString("manual save current graph");

    history_button[2].setTexture(clear);
    history_button[2].setPosition(GRAPH_WIDTH+30+2*auto_.getSize().x,GRAPH_HEIGHT/2-50);
    button_help[11].setString("shift + E");
}
void Sidebar::update_curr_help_button()
{
    current_button[0].setTexture(enter);
    current_button[0].setPosition(GRAPH_WIDTH+10,125);
    button_help[0].setString("shift + F");
    current_button[1].setTexture(recenter);
    current_button[1].setPosition(GRAPH_WIDTH+20+enter.getSize().x,125);
    button_help[1].setString("shift + R");
    current_button[2].setTexture(up);
    current_button[2].setPosition(GRAPH_WIDTH+30+enter.getSize().x*2,125);
    button_help[2].setString("up arrow");
    current_button[3].setTexture(left);
    current_button[3].setPosition(GRAPH_WIDTH+10,130+enter.getSize().y);
    button_help[3].setString("left arrow");
    current_button[4].setTexture(right);
    current_button[4].setPosition(GRAPH_WIDTH+20+enter.getSize().x,130+enter.getSize().y);
    button_help[4].setString("right arrow");
    current_button[5].setTexture(down);
    current_button[5].setPosition(GRAPH_WIDTH+30+enter.getSize().x*2,130+enter.getSize().y);
    button_help[5].setString("down arrow");
    current_button[6].setTexture(zoomin);
    current_button[6].setPosition(GRAPH_WIDTH+10,135+enter.getSize().y*2);
    button_help[6].setString("shift + '+'");
    current_button[7].setTexture(zoomout);
    current_button[7].setPosition(GRAPH_WIDTH+20+enter.getSize().x,135+enter.getSize().y*2);
    button_help[7].setString("shift + '-'");
    current_button[8].setTexture(help_button);
    current_button[8].setPosition(GRAPH_WIDTH+30+enter.getSize().x*2,135+enter.getSize().y*2);
    button_help[8].setString("press to turn off");

}
void Sidebar::history_update(sf::Font &font)
{

    history_bar->setTexture(historybar);
    history_bar->setPosition(GRAPH_WIDTH+5,GRAPH_HEIGHT/2);

    history.clear();
    history = _info->get_history();

    if(!history.empty())
    {

        for(int index = 0; index<5; index++)
        {
            if((history.size()-1)>=index)
            {
                history_box[index].setSize(his_box_size);
                history_box[index].setPosition(sf::Vector2f(his_box_loc.x,his_box_loc.y+index*his_box_size.y+index*10));
                history_box[index].setFillColor(sf::Color(211,229,214));
                history_box[index].setOutlineThickness(2);
                history_box[index].setOutlineColor(sf::Color(44,89,120));

                history_address[index].setFont(font);
                history_address[index].setFillColor(sf::Color::Black);
                history_address[index].setCharacterSize(20);
                history_address[index].setPosition(sf::Vector2f(his_text_loc.x,his_text_loc.y+index*his_box_size.y+index*10));
                history_address[index].setString(history[index+scrolled]);

                cross_sprite[index].setTexture(crosssign);
                cross_sprite[index].setPosition(sf::Vector2f(his_text_loc.x+his_box_size.x-40,his_text_loc.y+index*his_box_size.y+index*10));

            }

        }
    }

}
bool Sidebar:: if_clicked_history(const int& mouseX, const int &mouseY)
{
    if(history.empty())
        return false;
    else
    {
        for(int index =0; index < 5; index++)
        {
            if(history.size()-1>=index)
            {
                if(history_box[index].getGlobalBounds().contains(mouseX,mouseY))
                {
                    _info->change_input(history_address[index].getString());
                    return true;
                }
            }
        }
        return false;
    }
}
bool Sidebar::if_clicked_delete_history(const int &mouseX, const int &mouseY)
{
    if(history.empty())
        return false;
    else
    {
        for(int index =0; index < 5; index++)
        {
            if(history.size()-1>=index)
            {
                if(cross_sprite[index].getGlobalBounds().contains(mouseX,mouseY))
                {
                    _info->delete_history(index+scrolled);
                    if(!(scrolled+4>=history.size()))
                        scrolled = 0;
                    return true;
                }
            }
        }
        return false;
    }
}
bool Sidebar::if_scroll_on_history(const int& mouseX, const int& mouseY)
{
    if(history.empty())
        return false;
    else
    {
        if(history_bar[0].getGlobalBounds().contains(mouseX,mouseY))
        {
           return true;
        }
        return false;
    }
}
int Sidebar::scroll_history(const int scroll)
{
    if(!(scroll+4>=history.size()||scroll<0))
        scrolled = scroll;

    return scrolled;
}
int Sidebar:: if_clicked_his_button(const int& mouseX, const int &mouseY)
{
    for(int index = 0; index < 3; index ++)
    {
        if(history_button[index].getGlobalBounds().contains(mouseX,mouseY))
        {
            if(index == 0)
            {
                if(auto_on)
                {
                    auto_on = false;
                    auto_texture = auto_false;
                }
                else
                {
                    auto_on = true;
                    auto_texture = auto_;
                }
            }
            return AUTO_SAVE+index;
        }
    }
    return 0;
}
int Sidebar::if_clicked_curr_button(const int& mouseX, const int& mouseY)
{
    for(int index = 0; index < 9; index ++)
    {
        if(current_button[index].getGlobalBounds().contains(mouseX,mouseY))
        {
            if(index == 8)
            {
            if(help_on)
            {

                help_index = -1;
                help_on = false;
                help_button = helpb_off;

            }
            else
            {

                help_index = -1;
                help_on = true;
                help_button = helpb_on;
            }

            }
            return ENTER+index;
        }
    }
    return 0;
}
bool Sidebar:: if_show_help(const int& mouseX, const int& mouseY)
{
    for(int index = 0; index < 9; index ++)
    {
        if(current_button[index].getGlobalBounds().contains(mouseX,mouseY))
        {
            help_index = index;
            button_help[help_index].setPosition(mouseX-10,mouseY+20);
            return true;
        }
    }
    for(int index = 0; index<3; index++)
    {
        if(history_button[index].getGlobalBounds().contains(mouseX,mouseY))
        {
            help_index = index+9;
            button_help[help_index].setPosition(mouseX-15,mouseY-30);
            return true;
        }
    }
    if(current_bar.getGlobalBounds().contains(mouseX,mouseY))
    {
        help_index = 12;
        button_help[help_index].setPosition(mouseX+10,mouseY);
        return true;
    }
    help_index = -1;
    return false;
}
