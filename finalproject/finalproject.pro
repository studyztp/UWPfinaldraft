TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
#WINDOWS
# put SFML file in the same location as project
LIBS += -L"F:\Class work\cs3a\SFML-2.5.1\lib" #change this
LIBS += -L"F:\Class work\cs3a\SFML-2.5.1\bin" #change this

#MAC
#LIBS += -L"/usr/local/lib"

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window
CONFIG(debug  , debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-system -lsfml-network -lsfml-window

#WINDOWS
INCLUDEPATH += "F:\Class work\cs3a\SFML-2.5.1\include" #change this
DEPENDPATH += "F:\Class work\cs3a\SFML-2.5.1\include" #change this

SOURCES += \
        animation.cpp \
        background.cpp \
        coord_trans.cpp \
        function.cpp \
        graph.cpp \
        graph_info.cpp \
        lp.cpp \
        main.cpp \
        number.cpp \
        operator.cpp \
        plot.cpp \
        pop_up.cpp \
        rp.cpp \
        rpn.cpp \
        shuntingyard.cpp \
        sidebar.cpp \
        system.cpp \
        test_tokenizer.cpp \
        thex.cpp \
        token.cpp \
        tokenizer.cpp

HEADERS += \
    Description.h \
    NUMBERS.h \
    Queue.h \
    Stack.h \
    animation.h \
    background.h \
    coord_trans.h \
    features.h \
    function.h \
    graph.h \
    graph_info.h \
    list.h \
    lp.h \
    node.h \
    number.h \
    operator.h \
    plot.h \
    pop_up.h \
    rp.h \
    rpn.h \
    shuntingyard.h \
    sidebar.h \
    system.h \
    test_tokenizer.h \
    thex.h \
    token.h \
    tokenizer.h \
    work_report.h
