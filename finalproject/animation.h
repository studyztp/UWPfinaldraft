#ifndef ANIMATION_H
#define ANIMATION_H
#include "graph_info.h"
#include "system.h"
#include "sidebar.h"
#include "pop_up.h"
class Animation
{
public:
    Animation();                //create
    ~Animation();               //delete dynamic graph_info object
    void update();              //call system to update graph and background
                                //pop_up and sidebar to update their own features
    void draw();                //draw shapes and texts with sfml
    void render();              //sfml big three
    void processEvent();        //take event and react to it
    void run();                 //loop ends when program close
private:
    sf::RenderWindow window;
    sf::Event event;
    sf::Font font;

    Graph_info* _info;
    System system;          //graph and background
    Sidebar sidebar;        //everything in sidebar


    int command;            //take command and pass to system

    Pop_up pop_up;          //popup window

    string input, save;     //user input and temp save string
    sf::Text inputtext;     //text shown in screen for input

    int MouseX, MouseY;     //location of mouse
    int scroll, temp, polar, line, point;             //for user to scroll history bar
    bool shift,sb_changes,F, autosave, helpon;
                            //shift for detect shift
                            //sb change for sb to update when changes made
                            //F for input popup
                            //auto save for user to pick if auto save or manual save history
};

#endif // ANIMATION_H
