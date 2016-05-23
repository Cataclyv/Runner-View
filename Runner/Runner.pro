TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CXXFLAGS += -std=c++11 -Wall -Wextra

LIBS += -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += main.cpp \
    Balle.cpp \
    Bonus.cpp \
    Model.cpp \
    MovableElement.cpp \
    Obstacle.cpp \
    Score.cpp \
    View.cpp \
    GraphicElement.cpp \
    SlidingBackground.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    Balle.h \
    Bonus.h \
    Model.h \
    MovableElement.h \
    Obstacle.h \
    Score.h \
    View.h \
    GraphicElement.h \
    SlidingBackground.h

