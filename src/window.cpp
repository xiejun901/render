#include<SDL.h>
#include<string>
#include "window.h"
#include<stdio.h>
window::window(int w, int h, std::string n) :width(w),
                                             height(h),
                                             name(n),
                                             gWindow(nullptr),
                                             screen(nullptr)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		throw "SDL could not initialize!";
	}
	else
	{
		gWindow = SDL_CreateWindow(name.c_str(),
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			width,
			height,
			SDL_WINDOW_SHOWN);
		if (gWindow == nullptr)
		{
			printf("SDL could not create window! SDL_Error: %s\n", SDL_GetError());
			throw "SDL could not create window!";
		}
		else
		{
			renderer = SDL_CreateRenderer(gWindow, -1, 0);
			texture = SDL_CreateTexture(renderer,
				SDL_PIXELFORMAT_ARGB8888,
				SDL_TEXTUREACCESS_STREAMING,
				width, height);
			screen = SDL_CreateRGBSurface(0, width, height, 32,
				0x00FF0000,
				0x0000FF00,
				0x000000FF,
				0xFF000000);
            canvas = new Canvas(width, height, static_cast<int *>(screen->pixels));
		}
	}

}

void window::run()
{
    bool quit = false;
    SDL_Event e;
    int k = 0;
    canvas->clear();
    while (!_quit)
    {
        while (SDL_PollEvent(&e) != 0)
            handleEvent(e);
        update();
        draw();
        clear();
        show();
    }
}

void window::handleEvent(const SDL_Event & e)
{
    if (e.type == SDL_QUIT)
        onQuitEvent(e);
    if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
        onKeyEvent(e);
    else if (e.type == SDL_MOUSEBUTTONDOWN)
        onMouseEvent(e);
}

void window::onQuitEvent(const SDL_Event & e)
{
    quit();
}

void window::onKeyEvent(const SDL_Event & e)
{
    switch (e.key.keysym.sym)
    {
    case SDLK_ESCAPE:
        quit();
        break;
    case SDLK_UP:
    case SDLK_DOWN:
    case SDLK_LEFT:
    case SDLK_RIGHT:
    default:
        break;
    }
}

void window::onMouseEvent(const SDL_Event & e)
{
    switch (e.wheel.direction)
    {
    default:
        break;
    }
}

void window::quit()
{
    _quit = true;
}

void window::update()
{   
}

void window::clear()
{
    SDL_RenderClear(renderer);
}

void window::draw()
{
    //canvas->test();
    canvas->testDraw();
   
}

void window::show()
{
    SDL_UpdateTexture(texture, NULL, screen->pixels, screen->pitch);
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}

window::~window()
{
    SDL_FreeSurface(screen);
    screen = nullptr;
    SDL_DestroyWindow(gWindow);
    gWindow = nullptr;
    SDL_Quit();
}
