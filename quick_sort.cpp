#include<iostream>
#include<SDL2/SDL.h>
#include<time.h>
using namespace std;
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 640;


SDL_Window*window = SDL_CreateWindow("Quick Sort",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
SDL_Renderer*renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);
SDL_Point points[SCREEN_WIDTH];
int sdl_partition_r(SDL_Point points[], int l, int h)
{
	srand(time(NULL));
	int i = l;
	int j = h;
	int r = l+ rand()%(h-l+1);
	SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
	SDL_RenderDrawPoint(renderer, points[l].x, points[l].y);
	SDL_RenderDrawPoint(renderer, points[r].x, points[r].y);
	SDL_RenderPresent(renderer);
	swap(points[l].y,points[r].y);
	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderDrawPoint(renderer, points[l].x, points[l].y);
	SDL_RenderDrawPoint(renderer, points[r].x, points[r].y);
	SDL_RenderPresent(renderer);
	int p = points[l].y;
	while(i<=j)
	{
		if(points[i].y<=p)
		{
			i++;
		}
		if(points[j].y>p)
		{
			j--;
		}
		if(i<=j)
		{
			
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderDrawPoint(renderer, points[i].x, points[i].y);
			SDL_RenderDrawPoint(renderer, points[j].x, points[j].y);
			SDL_RenderPresent(renderer);
			swap(points[i].y,points[j].y);
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderDrawPoint(renderer, points[i].x, points[i].y);
			SDL_RenderDrawPoint(renderer, points[j].x, points[j].y);
			SDL_RenderPresent(renderer);

		}
	}
			
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderDrawPoint(renderer, points[l].x, points[l].y);
			SDL_RenderDrawPoint(renderer, points[j].x, points[j].y);
			SDL_RenderPresent(renderer);
			swap(points[j].y,points[l].y);
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderDrawPoint(renderer, points[l].x, points[l].y);
			SDL_RenderDrawPoint(renderer, points[j].x, points[j].y);
			SDL_RenderPresent(renderer);
			return j;
}
int sdl_partition(SDL_Point points[], int l, int h)
{
	int i = l;
	int j = h;
	int p = points[l].y;
	while(i<=j)
	{
		if(points[i].y<=p)
		{
			i++;
		}
		if(points[j].y>p)
		{
			j--;
		}
		if(i<=j)
		{
			
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderDrawPoint(renderer, points[i].x, points[i].y);
			SDL_RenderDrawPoint(renderer, points[j].x, points[j].y);
			SDL_RenderPresent(renderer);
			swap(points[i].y,points[j].y);
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderDrawPoint(renderer, points[i].x, points[i].y);
			SDL_RenderDrawPoint(renderer, points[j].x, points[j].y);
			SDL_RenderPresent(renderer);

		}
	}
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderDrawPoint(renderer, points[l].x, points[l].y);
			SDL_RenderDrawPoint(renderer, points[j].x, points[j].y);
			SDL_RenderPresent(renderer);
			swap(points[j].y,points[l].y);
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
			SDL_RenderDrawPoint(renderer, points[l].x, points[l].y);
			SDL_RenderDrawPoint(renderer, points[j].x, points[j].y);
			SDL_RenderPresent(renderer);
			return j;
}





void sdl_quick_sort_r(SDL_Point points[], int l, int h){
	int pile[h-l+1];
	int top =-1;
	pile[++top]=l;
	pile[++top]=h;
	while(top>=0)
	{
		h=pile[top--];
		l=pile[top--];
		int p =sdl_partition_r(points,l,h);
		if(p-1>l)
		{
			pile[++top]=l;
			pile[++top]=p-1;
		}
		if(p+1<h)
		{
			pile[++top]=p+1;
			pile[++top]=h;
		}
	}

}

void sdl_quick_sort(SDL_Point points[], int l, int h){
	int pile[h-l+1];
	int top =-1;
	pile[++top]=l;
	pile[++top]=h;
	while(top>=0)
	{
		h=pile[top--];
		l=pile[top--];
		int p =sdl_partition(points,l,h);
		if(p-1>l)
		{
			pile[++top]=l;
			pile[++top]=p-1;
		}
		if(p+1<h)
		{
			pile[++top]=p+1;
			pile[++top]=h;
		}
	}

}

int partition(int a[], int l, int h)
{
    int p = a[l];
    int i = l;
    int j =h;
    while(i<=j)
    {
	if(a[i]<=p)
	{
	  i++;
	}
	if(a[j]>p)
	{
	  j--;
	}
	if(i<=j)
	{
	   swap(a[i], a[j]);
	}
    }	
	swap(a[j], a[l]);
	return j;
}
void quick_sort(SDL_Point points[], int l, int h)
{
	if(l<h)
	{
          int j =sdl_partition(points,l,h);
	  quick_sort(points,l,j-1);
	  quick_sort(points, j+1,h);
	}
}
void iter_quick_sort(int a[], int l, int h)
{
	int pile[h-l+1];
	int top =-1;
	pile[++top]=l;
	pile[++top]=h;
	while(top>=0)
	{
		h=pile[top--];
		l=pile[top--];
		int p =partition(a, l, h);
		if(l<p-1)
		{
			pile[++top]=l;
			pile[++top]=p-1;
		}
		if(p+1<h){
			pile[++top]=p+1;
			pile[++top]=h;
		}
	}

}
int main(){
	srand(time(NULL));
	for(int i=0; i<SCREEN_WIDTH;++i)
	{
	   points[i].x = i;
	   points[i].y = SCREEN_HEIGHT-i;
	}
	bool on = true;
	while(on)
	{
		SDL_Event event;
		while(SDL_PollEvent(&event)!=0)
		{
			if(event.type == SDL_QUIT)
			{
				on = false;
			}
			SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

			for(int i=0; i<SCREEN_WIDTH;++i){
			SDL_RenderDrawPoint(renderer, points[i].x, points[i].y);
			SDL_RenderPresent(renderer);
			}
			sdl_quick_sort_r(points,0,SCREEN_WIDTH-1);
			 on = false;
			 SDL_Quit();
		}
		
	}

}
