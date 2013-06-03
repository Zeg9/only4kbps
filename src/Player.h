/*
***Only 4 KB/s***
A game by jmf
Copyright (c) 2013 jmf
*/
#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Player
{
public:
    Player();
    ~Player();
    static void setState(int state);   
    static void anim();
    static SDL_Surface *player;
    static int animstate;
    static int walkstate;
    static int oldtime;
    static bool update;
};

Player &getPlayer();

#endif //__PLAYER_H__
