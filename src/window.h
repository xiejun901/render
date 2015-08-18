#ifndef _WINDOW_H_
#define _WINDOW_H_
#include<string>
#include<SDL.h>
#include<stdio.h>
#include<Windows.h>

#include"../src/Canvas.h"
class window {
public:
	window(int w, int h, std::string n);
    void run();
    void handleEvent(const SDL_Event &e);
    void onQuitEvent(const SDL_Event &e);
    void onKeyEvent(const SDL_Event &e);
    void onMouseEvent(const SDL_Event &e);
    void quit();
    void update();
    void clear();
    void draw();
    void show();
    ~window();
private:
	int width;
	int height;
	std::string name;
	SDL_Window *gWindow;
	SDL_Surface *screen;
	SDL_Texture *texture;
	SDL_Renderer *renderer;
    Canvas *canvas;

    bool _quit = false;
};
#endif