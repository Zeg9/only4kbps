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
#include "Video.h"

int main(int argc, char *argv[])
{
    Video &d = getVideo();
    Scene &s = getScene();
    Player &p = getPlayer();
    d.init();//Initialize Video
    while(true)
    {
        d.clear();//Clear the screen to black
        Event::loopEvent();//Event handling
        if(Scene::walk == true)
        {
            Scene::sceneX = Scene::sceneX-5;//Move background
        }
        s.drawScene();
        p.anim();
        d.render();
        SDL_Delay(20);
        SDL_FreeSurface(Video::screen);
    }
}
