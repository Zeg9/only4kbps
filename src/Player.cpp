/*
***Only 4 KB/s***
A game by jmf
Copyright (c) 2013 jmf
*/
#include <iostream>
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "Player.h"
#include "Video.h"

SDL_Surface *Player::player = NULL;
int Player::oldtime = 0;
int Player::animstate = 0;
int Player::walkstate = 0;
bool Player::update = true;

Player::Player()
{
     Video &d = getVideo();
     Player::player = d.loadImg("../data/stand.png");
     std::cout<<Player::animstate<<"srsly"<<std::endl;
}
Player::~Player()
{
    SDL_FreeSurface(Player::player);
}

void Player::setState(int state)
{
    Player::animstate = state;
}

void Player::anim()
{
    Video &d = getVideo();
    int newtime;
    newtime=SDL_GetTicks();
    if(newtime-Player::oldtime>100)
    {
        if(Player::animstate == 1)
        {
            if(Player::walkstate == 0)
            {
                Player::walkstate = 1;
                Player::player = d.loadImg("../data/walk.png");
                Player::oldtime = newtime;
                Player::update = true;
            }
            else if (Player::walkstate == 1)
            {
                Player::walkstate = 0;
                Player::player = d.loadImg("../data/stand.png");
                Player::oldtime = newtime;
                Player::update = true;
            }
        }
        else if(Player::animstate == 2)
        {
            Player::player = d.loadImg("../data/jump.png");
            Player::update = true;
        }
        else
        {
            if(Player::update == true)
            {
                Player::update = false;
                Player::player = d.loadImg("../data/stand.png");
                
            }
        } 
    }
    d.onScreen(Player::player, 200, 390);
}

Player &getPlayer()
{
    static Player p;
    return p;
}
