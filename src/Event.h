/*
***Only 4 KB/s***
A game by jmf
Copyright (c) 2013 jmf
*/
#ifndef __EVENT_H__
#define __EVENT_H__
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Event
{
public:
    Event();
    ~Event();
    static void loopEvent();
};

SDL_Event &getEvent();

#endif //__OBJECT_H__
