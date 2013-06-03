/*
***Only 4 KB/s***
A game by jmf
Copyright (c) 2013 jmf
*/
#ifndef __SCENE_H__
#define __SCENE_H__
#include <string>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Scene
{
public:
    Scene();
    ~Scene();
    static void setBgd(int nr);
    static void drawScene();
    static SDL_Surface *scene;
    static int sceneNr;
    static int sceneX;
    static bool walk;
};

Scene &getScene();

#endif //__SCENE_H__
