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

    // The screen will be a loop that can handle events, when the X button is clicked, then it close.
    SDL_Event event;
    bool running = true;
    int x, y, w, h;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
                break;
            }
        }

        SDL_GetWindowSize( window, &w, &h );

        // SDL_GetWindowPosition( window, &x, &y );

        cout << w << "," << h << endl;
    }

    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}