#include<iostream>
#include<SDL2/SDL.h>
#include<time.h>
using namespace std;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;
SDL_Window*window = SDL_CreateWindow("bubbleSort", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
SDL_Renderer*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
void bubble_sort(SDL_Point points[]){
	for(int i=0; i<SCREEN_HEIGHT-1;++i)
	{
	  for(int j=0; j<SCREEN_HEIGHT-i-1;++j)
	  {
		if(points[j].y>points[j+1].y)
		{
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderDrawPoint(renderer, points[j].x, points[j].y);
			SDL_RenderDrawPoint(renderer, points[j+1].x, points[j+1].y);
			SDL_RenderPresent(renderer);
			swap(points[j].y, points[j+1].y);
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderDrawPoint(renderer, points[j].x, points[j].y);
			SDL_RenderDrawPoint(renderer, points[j+1].x, points[j+1].y);
			SDL_RenderPresent(renderer);
		}
	  }
	}

}	
int main(){
	srand(time(NULL));
	bool on = true;
	SDL_Point points[SCREEN_WIDTH];
	for(int i=0; i<SCREEN_WIDTH;++i){
		points[i].x=i;
		points[i].y=rand()%SCREEN_WIDTH;
	}
	while(on){
		SDL_Event e;
		while(SDL_PollEvent(&e)){
			if(e.type==SDL_QUIT){
				on = false;
			}
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer,0xFF, 0xFF, 0xFF, 0xFF);
			for(int i=0; i<SCREEN_HEIGHT;++i){
			        SDL_RenderDrawPoint(renderer, points[i].x, points[i].y);
				SDL_RenderPresent(renderer);
			}
			bubble_sort(points);	
			
			SDL_Quit(); 
			on = false;
		}
	}
}
