#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

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

class Sprite {
    private:
        SDL_Surface * image;
        SDL_Rect rect;

        int origin_x, origin_y;

    public:
        Sprite( Uint32 color, int x, int y, int w = 48, int h = 64 ) {
            image = SDL_CreateRGBSurface(0, w, h, 32, 0, 0, 0, 0 );

            SDL_FillRect( image, NULL, color );

            rect = image->clip_rect;

            origin_x = rect.w / 2;
            origin_y = rect.h / 2;

            rect.x = x - origin_x;
            rect.y = y - origin_y;
        }

        void update() {

        }

        void draw(SDL_Surface * destination) {
            SDL_BlitSurface( image, NULL, destination, &rect );
        }
};

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
    Uint32 red = SDL_MapRGB(screen->format, 255, 0, 0);
    SDL_FillRect(screen, NULL, white);

    Sprite object(red, window_width/2, window_height/2);
    object.draw( screen );

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