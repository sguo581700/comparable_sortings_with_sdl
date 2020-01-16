#include<iostream>
#include<SDL2/SDL.h>
#include<time.h>
using namespace std;
const int SCREEN_WIDTH = 480;
const int SCREEN_HEIGHT = 480;
SDL_Window*window = SDL_CreateWindow("heap sort", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
SDL_Renderer*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
void heapify(SDL_Point points[], int i, int n)
{
	int l = 2*i+1;
	int r = 2*i+2;
	int largest = i;
	if(l<=n-1&&points[l].y>points[largest].y)
	{
		largest = l;
	}
	if(r<=n-1&&points[r].y>points[largest].y)
	{
		largest = r;
	}
	if(largest!=i)
	{
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
		SDL_RenderDrawPoint(renderer, points[i].x, points[i].y);
		SDL_RenderDrawPoint(renderer, points[largest].x,points[largest].y);
		SDL_RenderPresent(renderer);
		swap(points[i].y, points[largest].y);
		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff, 0xff);
		SDL_RenderDrawPoint(renderer, points[i].x, points[i].y);
		SDL_RenderDrawPoint(renderer, points[largest].x, points[largest].y);
		heapify(points, largest, n);
	}
}
void heap_sort(SDL_Point points[], int n)
{
	for(int i=n/2-1;i>=0;--i)
	{
		heapify(points, i, n);
	}
	for(int i=n-1;i>=0;--i)
	{
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00,0x00);
		SDL_RenderDrawPoint(renderer, points[0].x, points[0].y);
		SDL_RenderDrawPoint(renderer, points[i].x, points[i].y);
		SDL_RenderPresent(renderer); 
		swap(points[0].y, points[i].y);
		SDL_SetRenderDrawColor(renderer, 0xff, 0xff, 0xff,0xff);
		SDL_RenderDrawPoint(renderer, points[0].x, points[0].y);
		SDL_RenderDrawPoint(renderer, points[i].x, points[i].y);
		SDL_RenderPresent(renderer);
		heapify(points, 0, i);
	}
}
int main(){
	srand(time(NULL));
	bool on = true;
	SDL_Point points[SCREEN_WIDTH];
	
	while(on)
	{
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
				points[i].y = rand()%SCREEN_WIDTH;
				SDL_RenderDrawPoint(renderer, points[i].x, points[i].y);
				SDL_RenderPresent(renderer);
			}
			heap_sort(points, SCREEN_WIDTH);
			on = false;
			SDL_Quit();
		}
	}		
}	
