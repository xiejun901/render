#ifndef _WINDOW_H_
#define _WINDOW_H_
#include<string>
#include<SDL.h>
#include<stdio.h>
#include<Windows.h>
class window {
public:
	window(int w, int h, std::string n) :width(w), 
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
				screen = SDL_GetWindowSurface(gWindow);
			}
		}
		
	};
	void run()
	{
		gHelloWorld = SDL_LoadBMP("hello.bmp");
		if (gHelloWorld == NULL)
			printf("Unable to load image %s! SDL Error: %s\n", "hello.bmp", SDL_GetError());
		bool quit = false;
		SDL_Event e;
		while (!quit)
		{
			while (SDL_PollEvent(&e) != 0)
			{
				if (e.type == SDL_QUIT)
					quit = true;
			}
			SDL_BlitSurface(gHelloWorld, NULL, screen, NULL);
			SDL_UpdateWindowSurface(gWindow);
		}
	}
	~window()
	{
		SDL_FreeSurface(gHelloWorld);
		gHelloWorld = nullptr;
		SDL_FreeSurface(screen);
		screen = nullptr;
		SDL_DestroyWindow(gWindow);
		gWindow = nullptr;
		SDL_Quit();
	}
private:
	int width;
	int height;
	std::string name;
	SDL_Window *gWindow;
	SDL_Surface *screen;
	SDL_Surface *gHelloWorld;
};
#endif