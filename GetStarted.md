# Project Overview

This is a graphing calculator simulator project built based on the [SFML](https://www.sfml-dev.org "sfml-dv.org"), a simple multi-media library. 

It is able to function like a real graphing calculator. For detail functionailities, please check the [Functionaility](Functionaility.md) section.


# Getting Started

## Table of Contents

* [Project Overview](#project-overview)
  * [Quick Start](#quick-start)
  * [Graphing Calculator Instructions](#graphing-calculator-instructions)
  * [Error and Suggestion](#error-and-suggestion)



# Quick Start

The repository only provides the source codes of the simulator. 

To compile the code, the following tools are required:


1. C++ compiler or compiling software (ex. [Qt Creator](https://www.qt.io/product/development-tools "QtCreator website"), [VSCode](https://code.visualstudio.com "VSCode Website"))
2. [SFML library](https://www.sfml-dev.org/tutorials/2.5/start-vc.php "sfml-tutorial")


If it compiles and builds correctly, you should see the Graphic Calculator window that looks like this:

![GraphicCalculatorWindow](doc_res/GraphingCalculatorUI.jpg)

# Graphing Calculator Instructions

For video explantions on the instructions, please click on the red button

 [![VideoInstruction](https://upload.wikimedia.org/wikipedia/commons/0/09/YouTube_full-color_icon_%282017%29.svg)](https://youtu.be/PvxouDXfDf0)

For detail commands, please check the [Functionaility](Functionaility.md) section.


## Basic Instructions
In this section, it will introduce the basic instructions to use the graphing calculator.

You can also press the button ![helpon](build-finalproject-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/helpon.jpg) on the right panel to get breif instructions on each button.

By pressing the button ![helpoff](build-finalproject-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/helpoff.jpg), the help messages will disapear. 


## Table of Instructions
* [Basic Instructions](#basic-instructions)
  * [Enter Function](#enter-function)
  * [Move Around Graph](#move-around-graph)
  * [Zoom In/Out](#zoom-in/out)
  * [Save History](#save-history)
  * [Change Graphing Mode](#change-graphing-mode)



## Enter Function
To change the function, first press the button ![ButtonEnter](build-finalproject-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/enter.jpg) on the right panel or press 'Shift + F' on keyboard

Then, you will see a pop-up box on the left that looks like this:


![PopupBox](doc_res/EnterExample.jpg)


Type in the function on the box with your keyboard and finish with pressing the enter key on your keyboard.

If you enter an incorrect graphing function, you will see a yellow warnning sign at the end of the box. The warnning sign will dispear when you enter a correct graphing function.

Below is an example:


![IncorrectExample](doc_res/IncorrectExample.jpg)

To exit the input mode, press 'ESC' on the keyboard or enter a correct function. 


## Move Around Graph

You can move around the graph using the right panel ![Left](build-finalproject-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/left.jpg)![Right](build-finalproject-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/right.jpg)![Up](build-finalproject-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/up.jpg)![Down](build-finalproject-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/down.jpg) or the arrow keys on your keyboard.
They will both allow you to shift Left/Right/Up/Down on the graph.

If you want to move back to the center, press the button ![Recenter](build-finalproject-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/recenter.jpg) or 'Shift + R ' on your keyboard.


## Zoom In/Out

You can zoom in/out on the graph by pressing ![In](build-finalproject-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/in.jpg)![Out](build-finalproject-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/out.jpg) or pressing ' Shift + '+' '/' Shift + '-' '.

Using the mouse cursor allows you to zoom in/out at a specific points. You can do it by pointing the mouse cursor at a point on the graph and srcolling up/down. 

## Save History

You can turn on/off the autometic save by pressing the button ![on](build-finalproject-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/autosave.jpg)![off](build-finalproject-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/autosave_false.jpg) to autometically save the histories.

Or you can manually save the history by pressing the button ![save](build-finalproject-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/save.jpg)

If you want to delete any histories, you can press the cross ![cross](build-finalproject-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/cross.jpg) or use the clear button ![clear](build-finalproject-Desktop_Qt_5_13_1_MinGW_64_bit-Debug/clear.jpg) to clear all histories. 


## Change Graphing Mode

There are two graphing mode. One is Linear and another is Polar.
To switch between Linear and Polar graphing mode, press the ' Shift + P ' on your keyboard.

There are two ways to graph the graph. One is using dots, and another is using line.
Both ways can exist at the same time, but at least one needs to be on. 
To turn on the doting, press ' Shift + W '.
To turn on the lineing, press ' Shift + Q'.

To increse the density of the doting, you can press ' Shift + A '.
To decrease the density of the doting, you can press ' Shift + S '.


# Error and Suggestion

If you experience any error or have any suggestions for the simulator, please leave a comment on the discussion page.
