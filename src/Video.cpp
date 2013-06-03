/*
***Only 4 KB/s***
A game by jmf
Copyright (c) 2013 jmf
*/
#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Video.h"

SDL_Surface *Video::screen = NULL;

void Video::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    Video::screen = SDL_SetVideoMode(640, 480, 32,SDL_SWSURFACE );
    SDL_WM_SetCaption( "Only4KBps", NULL ); 
}

SDL_Surface* Video::loadImg(std::string filename)
{
    std::cout<<"Loading"<<filename<<"..."<<std::endl;
    SDL_Surface* loadedImage = NULL;
    SDL_Surface* optimizedImage = NULL;
    loadedImage = IMG_Load(filename.c_str()); 
    std::cout<<"Don't forget to fix this!!!!!!!!!!!!!!!!!!!!"<<std::endl;
    //FIX THIS. NOW!!!
    /*
    if(loadedImage != NULL)
    {
        std::cout<<"Okay. You forgot to do this alpha shit..."<<std::endl;
        optimizedImage = SDL_DisplayFormatAlpha(loadedImage);
        SDL_FreeSurface(loadedImage);
    } 
    */
    return loadedImage;
    //return optimizedImage;
}

void Video::onScreen(SDL_Surface *surf, int x, int y)
{
     SDL_Rect position;
     position.x = x;
     position.y = y;
     SDL_BlitSurface(surf, 0, screen, &position);
}

void Video::render()
{
    SDL_Flip(Video::screen);
}


void Video::clear()
{
    SDL_FillRect(screen,0,SDL_MapRGB(screen->format,0,0,0));
}

Video &getVideo()
{
    static Video d;
    return d;       
}
