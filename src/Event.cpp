/*
***Only 4 KB/s***
A game by jmf
Copyright (c) 2013 jmf
*/
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Event.h"
#include "Player.h"
#include "Scene.h"

//extern bool quit_engine;


Event::Event()
{
}

Event::~Event()
{
}

void Event::loopEvent()
{
    Player &player = getPlayer();
    Scene &scene = getScene();
    SDL_Event &event = getEvent();
    int x=0;
    int y=0;
    int n=0;
    while(SDL_PollEvent(&event))
    {
        if(event.type==SDL_QUIT)
        {
        	//quit_engine = true;
        }
        if(event.type==SDL_KEYDOWN)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_RIGHT:
                    player.setState(1);
                    Scene::walk = true;
                break;
                case SDLK_UP:
                     player.setState(2);
                break;
                default: break;
            }
        }
        if (event.type==SDL_KEYUP)
        {
            switch(event.key.keysym.sym)
            {
                case SDLK_RIGHT:
                player.setState(0);
                Scene::walk = false;
				break;
				case SDLK_UP:
				player.setState(0);
				break;
				default: break;
            }
        }
    }
}

SDL_Event &getEvent()
{
    static SDL_Event event;
    return event;
}
