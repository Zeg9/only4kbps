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
#include "Scene.h"
#include "Video.h"

SDL_Surface *Scene::scene = NULL;
int Scene::sceneNr = 0;
int Scene::sceneX = 0;
bool Scene::walk = false;

Scene::Scene()
{
     Video &d = getVideo();
     Scene::scene = d.loadImg("../data/scene1.png");
}
Scene::~Scene()
{
    SDL_FreeSurface(Scene::scene);
}

void Scene::setBgd(int nr)
{
    Scene::sceneNr = nr;
}

void Scene::drawScene()
{
    Video &d = getVideo();
    d.onScreen(Scene::scene, Scene::sceneX, 0);
}

Scene &getScene()
{
    static Scene s;
    return s;       
}
