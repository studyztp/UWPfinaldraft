#include "animation.h"

Animation::Animation()
{
    _info = new Graph_info;                                 //dynamic graph_info object
    system.set_info(_info);                                 //pass it to the objects to connect them together
    sidebar.set_info(_info);
    pop_up.set_info(_info);

    system.locate_center_x();                               //if domain isn't default
                                                            //this function can help modified the center

    window.create(sf::VideoMode(SCREEN_WIDTH,SCREEN_HEIGHT),"Graphing Calculator");
    window.setFramerateLimit(SCREEN_RATE);

    if(!font.loadFromFile("Roboto-Thin.ttf"))               //create font
    {
        cout<<"Unable to load Roboto-Thin.ttf"<<endl;
        exit(1);
    }

    inputtext.setFont(font);                                //initialize text
    inputtext.setFillColor(sf::Color::Black);

    F = false;                                              //initialize bool
    autosave = false;
    sb_changes = true;
    shift = false;
    polar = false;
    helpon= false;

    input = "";                                             //string
    save = "";

    MouseX = 0;                                             //value
    MouseY = 0;
    scroll = 0;
    command = 0;

}
Animation::~Animation()
{
    delete _info;                                           //delete dynamic object
}
void Animation:: update()
{

    command =system.step(command);                                   //system takes step
                                                                     //initialize command
    system.update();                                                //if step taken
                                                                //then update graph and bg
                                                                //else update bg only
    if(F)                                                   //if input is processing
    {
        pop_up.update();                                    //update popup
        inputtext.setPosition(pop_up.get_ib_x()+3,pop_up.get_ib_y()+10);
                                                            //update shown text
    }


    if(sb_changes)                                          //if changes made with sb
    {
        sidebar.update(font);                               //update

        sb_changes = false;                                 //initilize bool
    }


}
void Animation::draw()
{

    system.draw(window);                                    //draw graph and bg
    if(F)                                                   //if input is processing
    {
        pop_up.draw(window);                                //draw pop_up
        window.draw(inputtext);                             //draw shown text
    }
    sidebar.draw(window);                                   //draw sidebar


}
void Animation::render()
{
    window.clear();
    draw();
    window.display();
}
void Animation::processEvent()
{
    while (window.pollEvent(event)) {
        switch (event.type) {
        case sf::Event::Closed:
            if(autosave)                                    //if autosave is on
                _info->save_history(_info->get_input());    //auto save the last graph
            _info->write_history_to_file();                 //write info in file
            window.close();                                 //close window
            break;
        case sf::Event::KeyPressed:
            switch (event.key.code) {
            case sf::Keyboard::LShift:
                shift = true;                               //LS RS can enable shift
                                                            //while pressing it without releasing
                break;
            case sf::Keyboard::RShift:
                shift = true;
                break;
            case sf::Keyboard::Equal:
                if(shift&&!F)                               //if input is not on and shift is pressed
                {
         //           graph.zoom_in(info);
                    command = ZOOMIN;                       //give command
                    cout<<"+"<<endl;
                }
                break;
            case sf::Keyboard::Hyphen:
                if(shift&&!F)
                {
                  //  graph.zoom_out(info);
                    command = ZOOMOUT;
                    cout<<"-"<<endl;
                }
                break;
            case sf::Keyboard::P:
            {
                if(shift&&!F)
                {
                    if(polar)
                    {
                        polar = false;
                        command = POLAR_OFF;
                    }
                    else
                    {
                        polar = true;
                        command = POLAR_ON;
                    }
                }
                break;
            }
            case sf::Keyboard::Q:
            {
                if(shift&&!F)
                {
                    if(line&&point)
                    {
                        line = false;
                        command = TURN_OFF_LINE;
                    }
                    else
                    {
                        line = true;
                        command = TURN_ON_LINE;
                    }
                }
                break;
            }
            case sf::Keyboard::W:
            {
                if(shift&&!F)
                {
                    if(line&&point)
                    {
                        point = false;
                        command = TURN_OFF_POINT;
                    }
                    else
                    {
                        point = true;
                        command = TURN_ON_POINT;
                    }
                }
                break;
            }
            case sf::Keyboard::Left:
                if(!F)
                {
               //     graph.pan_left(info);
                    command = PANLEFT;
                }
                break;
            case sf::Keyboard::Right:
                if(!F)
                {
                    command = PANRIGHT;
               //     graph.pan_right(info);
                }
                break;
            case sf::Keyboard::Up:
                if(!F)
                {
                    command = PANUP;
               //     graph.pan_up(info);
                }
                break;
            case sf::Keyboard::Down:
                if(!F)
                {
                    command = PANDOWN;
               //     graph.pan_down(info);
                }
                break;
            case sf::Keyboard::E:
            {
                if(shift&&!F)
                {
                  //  info.reset_histroy();
                    command = RESET_HIS;
                }
                break;
            }
            case sf::Keyboard::R:
                if(shift&&!F)
                {
                  //  info.reloate_center();
                    command = RECENTER;
                }
                break;
            case sf::Keyboard::A:
            {
                if(shift&&!F)
                {
                    command = ADD_POINT_AMOUNT;
                }
                break;
            }
            case sf::Keyboard::S:
            {
                if(shift&&!F)
                {
                    command = MINUS_POINT_AMOUNT;
                }
                break;
            }
            case sf::Keyboard::F:
                if((shift&&!F))
                {
                    F = true;
                    pop_up.update();
                    save = _info->get_input();                  //save infomation in case anything happen
                    if(autosave)
                        _info->save_history(save);
                    if(_info->is_polar())
                        input = "r=";
                    else
                        input = "f(x)=";
                    inputtext.setString(input);
                    window.pollEvent(event);                    //prevent "F"
                }
                break;
            case sf::Keyboard::Enter:
                if(F)
                {

                    if(system.check_for_input_error(input))//check for the correctness of input
                    {
                        pop_up.set_warning(true);          //if incorrect show error sign
                    }
                    else
                    {
                        input = system.deleteallspace(input);//if correct then modified the input
                        _info->change_input(input);          //change the input in _info object
                        command = CHANGE_INPUT;
                        system.step(command);
                        command = 0;
                        system.update();                    //update graph for rpn check
                        if(_info->is_error())               //if rpn check did not passed
                        {
                            _info->change_input(save);
                            pop_up.set_warning(true);       //warning pop up
                        }
                        else
                        {
                            pop_up.set_warning(false);      //else take down warning
                            save = system.deleteallspace(save);//modified save for auto save purpose
                            if(autosave)                    //if auto save is on
                                _info->save_history(save);  //save it
                            sb_changes= true;           //update sidebar
                            input = "";                     //initialize them
                            command = CHANGE_INPUT;         //give command to graph for new graph
                            F = false;                      //disable F
                        }

                    }

                }
                break;
                case sf::Keyboard::Escape:
               {
                if(F)
                {
                    F= false;                               //for F to disable
                    input = "";
                }
                }

            default:
                break;

            }
            break;
        case sf::Event::TextEntered:
        {

            if(F)
            {
                if(event.text.unicode<128)
                {

                    if(!input.empty())                  //delete "f(X)=" when user starts input
                    {
                        if(input == "f(x)=")
                        {
                            input="";
                            inputtext.setString(input);
                        }
                        if(input =="r=")
                        {
                            input = "";
                            inputtext.setString(input);
                        }
                    }

                    if(event.text.unicode!='\b')        //when input is not backsapce
                    {

                        input += event.text.unicode;    //add it to input
                        inputtext.setString(input);     //show it with sfml

                    }
                    else
                    {
                        if(!input.empty())              //when input is not empty
                        {
                            input.pop_back();           //delete the last letter
                            inputtext.setString(input);
                        }
                    }
                }
            }
            break;
        }
        case sf::Event::MouseWheelMoved:
        {
            if(!sidebar.if_scroll_on_history(MouseX,MouseY))//if the mouse is not
                                                            //scrolling on the history area
            {

            if(event.mouseWheel.delta==1)                   //scroll up
            {
                if(MouseX<=GRAPH_WIDTH/4)                   //pass command directly to system
                    system.step(PANLEFT);
                if(MouseX>=3*GRAPH_WIDTH/4)
                    system.step(PANRIGHT);
                if(MouseY<=GRAPH_HEIGHT/4)
                    system.step(PANUP);
                if(MouseY>=3*GRAPH_HEIGHT/4)
                    system.step(PANDOWN);
                system.step(ZOOMIN);
            }
            if(event.mouseWheel.delta==-1)                  //scroll down
            {
                if(MouseX<=GRAPH_WIDTH/4)
                    system.step(PANRIGHT);
                if(MouseX>=3*GRAPH_WIDTH/4)
                    system.step(PANLEFT);
                if(MouseY<=GRAPH_HEIGHT/4)
                    system.step(PANDOWN);
                if(MouseY>=3*GRAPH_HEIGHT/4)
                    system.step(PANUP);
                system.step(ZOOMOUT);
            }
            }
            if(sidebar.if_scroll_on_history(MouseX,MouseY))
            {
                if(event.mouseWheel.delta==1)               //when mouse scrolling on the history area
                {                                           //and scroll up
                                                            //vector move one to the front

                    scroll++;
                }
                else
                    scroll--;
                scroll = sidebar.scroll_history(scroll);   //pass the scroll to sidebar to see if it reaches the limit of the vector history
                                                           //if not then scrolled succesfully
            }
                sb_changes = true;                          //sb changes
            break;
        }
        case sf::Event::MouseButtonPressed:
        {
            if(!F)                                          //only when not inputting
            {
            command = sidebar.if_clicked_his_button(event.mouseButton.x,event.mouseButton.y);
            temp=sidebar.if_clicked_curr_button(event.mouseButton.x,event.mouseButton.y);
                                                            //use command to carry the return int
                                                            //if mouse is not clicked on the button
                                                            //then return 0
                                                            //else return command
            if(event.mouseButton.button == sf::Mouse::Left )//if left click with mouse
            {
                save = _info->get_input();                  //save the input for saftly purpose
                if(sidebar.if_clicked_delete_history(event.mouseButton.x,event.mouseButton.y))
                {                                           //if true then it will deleted the corrsponding history
                                                            //and sb changes
                    sb_changes = true;
                }
                else if(sidebar.if_clicked_history(event.mouseButton.x,event.mouseButton.y))
                {                                           //if true it will change graph to the clicked history graph
                    if(autosave)                            //if autosave is on
                        _info->save_history(save);          //save the one got replaced
                    sb_changes = true;                      //sb changes
                    command = CHANGE_INPUT;                 //give system order to graph
                }
                else if(command)                            //if button is clicked
                {
                    switch (command) {
                    case AUTO_SAVE:                         //enable or disable autosave
                        if(autosave)
                            autosave=false;
                        else
                            autosave = true;

                        break;
                    case SAVE:                              //mannual save
                        _info->save_history(_info->get_input());
                        break;
                    case CLEAR:                             //clear all history
                        _info->reset_histroy();
                        break;
                    }
                    command = 0;
                    sb_changes = true;
                }
                else if(temp)
                {
                    command = temp;
                    if(command == ENTER)
                    {
                        F = true;
                        pop_up.update();
                        save = _info->get_input();                  //save infomation in case anything happen
                        input = "f(x)=";
                        inputtext.setString(input);
                        command = 0;
                    }
                    if(command == HELP_BUTTON)
                    {
                        if(helpon)
                            helpon = false;
                        else
                            helpon = true;
                        sb_changes = true;
                    }
                }
            }
            }
            break;
        }
        case sf::Event::MouseMoved:
        {
            MouseX = event.mouseMove.x;                       //record mouse loc
            MouseY = event.mouseMove.y;
            if(helpon)
            {
                if(sidebar.if_show_help(event.mouseMove.x,event.mouseMove.y))
                {
                    sb_changes = true;
                }
            }
            break;
        }
        case sf::Event::KeyReleased:
                switch (event.key.code)
                {

            case sf::Keyboard::LShift:                      //disable shift when relase
                    shift= false;
                    break;
                case sf::Keyboard::RShift:
                    shift = false;
                    break;
                default:
                    break;

            }
            break;
        //

        default:
            break;
        }
        break;
    }

}
void Animation:: run()
{
    while(window.isOpen())
    {
        processEvent();
        update();
        render();

    }
}

