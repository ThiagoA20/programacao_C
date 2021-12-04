#include <SDL2/SDL.h>
#include <iostream>

#define window_width 400
#define window_height 200
#define fps 60

using namespace std;

// Screen framerate
void cap_framerate(Uint32 starting_tick) {
    if ( (1000 / fps) > SDL_GetTicks() - starting_tick ) {
        SDL_Delay( 1000 / fps - (SDL_GetTicks() - starting_tick));
    } 
}

int main(int argc, char *argv[] ) {
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window * window = NULL;

    window = SDL_CreateWindow(
        "Test",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        window_width,
        window_height,
        SDL_WINDOW_RESIZABLE
    );

    if ( window == NULL ) {
        cout << "There is a error initing the window" << endl
        << SDL_GetError() << endl;
    }

    Uint32 starting_tick;
    bool running = true;
    SDL_Event event;

    // Change window collor
    SDL_Surface *screen = SDL_GetWindowSurface(window);
    Uint32 white = SDL_MapRGB(screen->format, 255, 255, 255);
    SDL_FillRect(screen, NULL, white);
    SDL_UpdateWindowSurface( window );


    while (running) {
        starting_tick = SDL_GetTicks();

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
        }

        cap_framerate(starting_tick);
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}