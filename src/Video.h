/*
***Only 4 KB/s***
A game by jmf
Copyright (c) 2013 jmf
*/
#ifndef __VIDEO_H__
#define __VIDEO_H__
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Video
{
public:
    static void init();   
    SDL_Surface* loadImg(std::string filename);
    static void onScreen(SDL_Surface *surf, int x, int y);
    static void render();
    static void clear();
    static SDL_Surface *screen;
    
};

Video &getVideo();

#endif //__VIDEO_H__
