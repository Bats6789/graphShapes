/*
 * Name: graphShapes.c
 * Auth: Blake Wingard
 * Desc: Graph simple geometric shapes.
 * Vers: 1.0.0 02/14/2020 CBW - Original code.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

int main( int argc, char **argv ){
	int quit;
	int ctrl;
	int alt;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Event event;

	// start SDL
	if( SDL_Init( SDL_INIT_EVERYTHING ) != 0 ){
		SDL_Log( "Unable to initialize SDL: %s", SDL_GetError());
		return( EXIT_FAILURE );
	}
	SDL_Log( "Initialized successfully" );
	atexit( SDL_Quit );

	if( SDL_CreateWindowAndRenderer( SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_FULLSCREEN_DESKTOP, &window, &renderer )){
		SDL_Log( "Couldn't create window and renderer: %s", SDL_GetError());
		return( EXIT_FAILURE );
	}
	SDL_Log( "window and renderer created successfully" );
	
	if( SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 ) < 0 ){
		SDL_Log( "Unable to changer renderer draw color: %s", SDL_GetError());
		return( EXIT_FAILURE );
	}

	if( SDL_RenderClear( renderer ) < 0 ){
		SDL_Log( "Unable to clear renderer: %s", SDL_GetError());
		return( EXIT_FAILURE );
	}

	SDL_RenderPresent( renderer );

	quit = 0;
	ctrl = 0;
	alt = 0;
	while( !quit ){
		while( SDL_PollEvent( &event )){
			if( event.type == SDL_KEYDOWN ){
				// quit
				if( event.key.keysym.sym == SDLK_ESCAPE || event.key.keysym.sym == SDLK_q ||
						( ctrl == 1 && event.key.keysym.sym == SDLK_w ) || event.type == SDL_QUIT || 
						( alt == 1 && event.key.keysym.sym == SDLK_F4 )){
					quit = 1;
				} else if( event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL ){
					ctrl = 1;
				} else if( event.key.keysym.sym == SDLK_LALT || event.key.keysym.sym == SDLK_RALT ){
					alt = 1;
				}
			} else if( event.type == SDL_KEYUP ){
				if( event.key.keysym.sym == SDLK_LCTRL || event.key.keysym.sym == SDLK_RCTRL ){
					ctrl = 0;
				} else if( event.key.keysym.sym == SDLK_LALT || event.key.keysym.sym == SDLK_RALT ){
					alt = 0;
				}
			}
		}
		SDL_Delay( 100 );
	}
	// wait for user to select option
	// 	if file
	// 		display file menu for user to save graph
	// 	else if shape
	// 		drop down for shape
	// 			if user selects circle
	// 				prompt for center and radius.
	// 			else if user selects rectangle
	// 				prompt user for start x, y, width, and length
	// 			else if user selects triangle
	// 				prompt user for x1, y1, x2, y2, x3, y3
	// 			else if user selects ellipse
	// 				prompt user for center, a, and b
	// 			else if user selects polygon
	// 				prompt user for center, number of sides, and side length
	// 			else
	// 				do nothing
	// 	else if view
	// 		drop down for view
	// 			bring up color menu
	// 				if user selects background
	// 					menu for modifying colors
	// 				else if user selects axis'
	// 					menu for modifying color
	// 				else if user selects shape
	// 					menu for modifying color
	// 				else
	// 					do nothing
	// 	else
	// 		do nothing
	//
	// end SDL
	return( EXIT_SUCCESS );
}
