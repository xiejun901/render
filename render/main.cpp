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
//int main(int argc, char * argv[])
//{
//	bool quit = false;
//	SDL_Event e;
//	if (!init())
//	{
//		printf("Failed to initialize!\n");
//	}
//	else
//	{
//		//Load media
//		if (!loadMedia())
//		{
//			printf("Failed to load media!\n");
//		}
//		else
//		{
//			//Apply the image
//			while (!quit)
//			{
//				while (SDL_PollEvent(&e) != 0)
//				{
//					if (e.type == SDL_QUIT)
//					{
//						quit = true;
//						printf("������˳�Ӵ\n");
//					}
//					else if (e.type == SDL_KEYDOWN)
//					{
//						printf("�㰴������Ӵ\n");
//						switch (e.key.keysym.sym)
//						{
//						case SDLK_UP:
//							printf("�㰴����Ӵ\n");
//							break;
//						case SDLK_DOWN:
//							printf("�㰴����Ӵ\n");
//							break;
//						case SDLK_LEFT:
//							printf("�㰴����Ӵ\n");
//							break;
//						case SDLK_RIGHT:
//							printf("�㰴����Ŷ\n");
//							break;
//						default:
//							printf("�㰴���������ġ�����������\n");
//							break;
//						}
//					}
//
//				}
//				SDL_Rect stretchRect;
//				stretchRect.x = 0;
//				stretchRect.y = 0;
//				stretchRect.w = 320;
//				stretchRect.h = 240;
//
//				SDL_Surface *optimizedSurface = SDL_ConvertSurface(gHelloWorld, gScreenSurface->format, NULL);
//				SDL_BlitScaled(gHelloWorld, NULL, gScreenSurface, &stretchRect);
//				SDL_UpdateWindowSurface(gWindow);
//			}
//		}
//	}
//	close();
//	return 0;
//}

int main(int argc, char * argv[])
{
	window win(640, 480, "xx");
	win.run();
	return 0;
}

//int main(int argc, char * argv[])
//{
//	SDL_Window *sdlWindow = SDL_CreateWindow("xxxx",
//											SDL_WINDOWPOS_UNDEFINED,
//											SDL_WINDOWPOS_UNDEFINED,
//											640,
//											480,
//											SDL_WINDOW_SHOWN);
//	SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, 0);
//	SDL_SetRenderDrawColor(sdlRenderer, 255, 255, 255, 255);
//	SDL_RenderClear(sdlRenderer);
//	SDL_RenderPresent(sdlRenderer);
//	SDL_Surface *screen = SDL_CreateRGBSurface(0, 640, 480, 32,
//		0x00FF0000,
//		0x0000FF00,
//		0x000000FF,
//		0xFF000000);
//	SDL_Texture *sdlTexture = SDL_CreateTexture(sdlRenderer,
//												SDL_PIXELFORMAT_ARGB8888,
//												SDL_TEXTUREACCESS_STREAMING,
//												640, 480);
//	for (int i = 0; i < 480 ; ++i)
//	{
//		int color;
//		if (i < 100)
//			color = 0x00FF0000;
//		else if (i < 200)
//			color = 0xFFFF0000;
//		else if (i < 300)
//			color = 0x000000FF;
//		else
//			color = 0xFFFF0000;
//		for (int j = 0; j < 640; ++j)
//		{
//
//			*((int *)screen->pixels + i * 640 + j) = color;
//		}
//	}
//	SDL_UpdateTexture(sdlTexture, NULL, screen->pixels, screen->pitch);
//	SDL_RenderClear(sdlRenderer);
//	SDL_RenderCopy(sdlRenderer, sdlTexture, NULL, NULL);
//	SDL_RenderPresent(sdlRenderer);
//	return 0;
//}