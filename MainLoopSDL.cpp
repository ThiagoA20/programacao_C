#include <SDL2/SDL.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[] ) {
    // Inicialize the sdl library
    SDL_Init( SDL_INIT_EVERYTHING );

    // Create a new window
    SDL_Window * window;

    window = SDL_CreateWindow(
        "Test",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        400,
        200,
        SDL_WINDOW_RESIZABLE
    );

    if ( window == NULL ) {
        cout << "There is a error initing the window" << endl
        << SDL_GetError() << endl;
    }

    SDL_Event event;
    bool running = true;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
        }
    }

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}