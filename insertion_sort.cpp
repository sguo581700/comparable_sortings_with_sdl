#include<iostream>
#include<SDL2/SDL.h>
#include<time.h>
using namespace std;
const int SCREEN_WIDTH =640;
const int SCREEN_HEIGHT=640;
SDL_Window*window = SDL_CreateWindow("Insertion sort", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
SDL_Renderer*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

void sdl_insertion_sort(SDL_Point points[])
{
	for(int i=0; i<SCREEN_HEIGHT;++i)
	{
		for(int j=i; j>=0;--j)
		{
			if(points[j+1].y<points[j].y){
				SDL_SetRenderDrawColor(renderer, 0x00,0x00,0x00,0x00);
				SDL_RenderDrawPoint(renderer, points[j].x, points[j].y);
				SDL_RenderDrawPoint(renderer, points[j+1].x,points[j+1].y);
				SDL_RenderPresent(renderer);
				swap(points[j].y, points[j+1].y);
				SDL_SetRenderDrawColor(renderer, 0xff,0xff,0xff,0xff);
				SDL_RenderDrawPoint(renderer, points[j].x, points[j].y);
				SDL_RenderDrawPoint(renderer, points[j+1].x, points[j+1].y);
				SDL_RenderPresent(renderer);
				}
		}
	}
}
int main()
{
	srand(time(NULL));
	bool on = true;
	SDL_Point points[SCREEN_HEIGHT];
	while(on){
		SDL_Event event;
		while(SDL_PollEvent(&event)!=0)
		{
			if(event.type==SDL_QUIT)
			{
				on = false;
			}
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
			for(int i=0; i<SCREEN_WIDTH;++i)
			{
				points[i].x = i;
				points[i].y = rand()%SCREEN_HEIGHT;
				SDL_RenderDrawPoint(renderer, points[i].x, points[i].y);
				SDL_RenderPresent(renderer);		
			}
			sdl_insertion_sort(points);
			
		}
		
			on = false;
			SDL_Quit();
	}
}
