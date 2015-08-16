#include<SDL.h>
#include<Windows.h>
#include<stdio.h>


#include "../src/window.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Surface* gHelloWorld = NULL;
bool init()
{
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		gWindow = SDL_CreateWindow("SDL Tutorial", 
									SDL_WINDOWPOS_UNDEFINED, 
									SDL_WINDOWPOS_UNDEFINED, 
									SCREEN_WIDTH, 
									SCREEN_HEIGHT, 
									SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("SDL could not create window! SDL_Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			gScreenSurface = SDL_GetWindowSurface(gWindow);
		}
	}
	return success;
}

bool loadMedia()
{
	bool success = true;
	gHelloWorld = SDL_LoadBMP("hello.bmp");
	if (gHelloWorld == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", "hello.bmp", SDL_GetError());
		success = false;
	}
	return success;
}
void close()
{
	SDL_FreeSurface(gHelloWorld);
	gHelloWorld = NULL;
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	SDL_Quit();
}
int main(int argc, char * argv[])
{
	bool quit = false;
	SDL_Event e;
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Apply the image
			while (!quit)
			{
				while (SDL_PollEvent(&e) != 0)
				{
					if (e.type == SDL_QUIT)
					{
						quit = true;
						printf("你点了退出哟\n");
					}
					else if (e.type == SDL_KEYDOWN)
					{
						printf("你按键盘了哟\n");
						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
							printf("你按了上哟\n");
							break;
						case SDLK_DOWN:
							printf("你按了下哟\n");
							break;
						case SDLK_LEFT:
							printf("你按了左哟\n");
							break;
						case SDLK_RIGHT:
							printf("你按了又哦\n");
							break;
						default:
							printf("你按的是其他的。。。。。。\n");
							break;
						}
					}

				}
				SDL_Rect stretchRect;
				stretchRect.x = 0;
				stretchRect.y = 0;
				stretchRect.w = 320;
				stretchRect.h = 240;

				SDL_Surface *optimizedSurface = SDL_ConvertSurface(gHelloWorld, gScreenSurface->format, NULL);
				SDL_BlitScaled(gHelloWorld, NULL, gScreenSurface, &stretchRect);
				SDL_UpdateWindowSurface(gWindow);
			}
		}
	}
	close();
	return 0;
}

//int main(int argc, char * argv[])
//{
//	window win(640, 480, "xx");
//	win.run();
//	return 0;
//}