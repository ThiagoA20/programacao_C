#include <SDL2/SDL.h>
#include <iostream>
#include <vector>

#define fps 60
#define window_width 700
#define window_height 400

using namespace std;

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

        // void update(string keyname) {
        //     if (keyname == "Down" || keyname == "Up") {
        //         if (keyname == "Down") {
        //             rect.y += 50;
        //         } else {
        //             rect.y -= 50;
        //         }
        //     } else {
        //         if (keyname == "Left") {
        //             rect.x -= 50;
        //         } else {
        //             rect.x += 50;
        //         }
        //     }
        // }

        void update() {

        }

        void draw(SDL_Surface * destination) {
            cout << "Y: " << rect.y << " " << "X: " << rect.x << endl;
            SDL_BlitSurface( image, NULL, destination, &rect );
        }

        SDL_Surface * get_image() const {
            return image;
        }

        bool operator==(const Sprite &other) const {
            return (image == other.get_image());
        }
};

class SpriteGroup {
    private:
        vector <Sprite*> sprites;
        int sprites_size;


    public:

        SpriteGroup copy() {
            SpriteGroup new_group;

            for (int i = 0; i < sprites_size; i++) {
                new_group.add( sprites[i] );
            }

            return new_group;
        }

        void add(Sprite * sprite) {
            sprites.push_back( sprite );
            sprites_size = sprites.size();
        }

        void remove(Sprite sprite_object) {
            for ( int i = 0; i < sprites_size; i++ ) {
                if (*sprites[i] == sprite_object) {
                    sprites.erase(sprites.begin() + i);
                }

                sprites_size = sprites.size();
            }
        }

        bool has(Sprite sprite_object) {
            for ( int i = 0; i < sprites_size; i++ ) {
                if (*sprites[i] == sprite_object) {
                    return true;
                }
            }

            return false;
        }

        void update() {
            if (!sprites.empty()) {
                for ( int i = 0; i < sprites_size; i++ ) {
                    sprites[i]->update();
                }
            }
        }

        void draw(SDL_Surface *destination) {

            if (!sprites.empty()) {
                for ( int i = 0; i < sprites_size; i++ ) {
                    sprites[i]->draw(destination);
                }
            }
        }

        void empty() {
            sprites.clear();

            sprites_size = sprites.size();
        }

        int size() {
            return sprites_size;
        }

        vector <Sprite*> get_sprites() {
            return sprites;
        }
};

int main(int argc, char *argv[]) {

    // 1º init sdl
    SDL_Init(SDL_INIT_EVERYTHING); // ----------------------------------- Init SDL functions


    // 2º create window
    SDL_Window * window = NULL; // --------------------------------------------- Set SDL window variable as window

    window = SDL_CreateWindow(
        "Flappy Bird A.I. V1",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        window_width,
        window_height,
        SDL_WINDOW_RESIZABLE
    ); // --------------------------------------------------------------- Parameters: title, x, y, w, h, flags...

    if ( window == NULL ) {
        cout << "There is a error initing the window" << endl
        << SDL_GetError() << endl;
    } // ---------------------------------------------------------------- Check if the window was created


    // 3º Event listener
    SDL_Event event;
    bool running = true;
    Uint32 starting_tick;

    SDL_Surface *screen = SDL_GetWindowSurface(window);
    Uint32 white = SDL_MapRGB(screen->format, 255, 255, 255);
    Uint32 red = SDL_MapRGB(screen->format, 255, 0, 0);
    Uint32 blue = SDL_MapRGB(screen->format, 0, 0, 255);
    SDL_FillRect(screen, NULL, white);

    Sprite object111(red, window_width/2, window_height/2);
    Sprite obj222(blue, window_width/2-100, window_height/2-100);
    SpriteGroup active_sprites;

    active_sprites.add(&object111);
    active_sprites.add(&obj222);
    active_sprites.draw( screen );

    SDL_UpdateWindowSurface( window );

    while (running) { // ------------------------------------------------ Start the main loop

        starting_tick = SDL_GetTicks(); // ------------------------------ Set starting tick for this while execution

        while (SDL_PollEvent(&event)) { // ------------------------------ Detect events
            switch (event.type) {
                case SDL_QUIT: // --------------------------------------- Quit when click on X
                    running = false;
                    break;
                // case SDL_KEYDOWN: // ------------------------------------ Print Key pressed
                    // string keyname;
                    // keyname = SDL_GetKeyName(event.key.keysym.sym);
                    // if (keyname == "Down" || keyname == "Up") {
                    //     object111.update(keyname);
                    //     object111.draw( screen );
                    // } else if (keyname == "Left" || keyname == "Right") {
                    //     object111.update(keyname);
                    //     object111.draw( screen );
                    // } else {
                    //     cout << keyname << " != " << "arrow" << endl;
                    // }
                    // SDL_UpdateWindowSurface( window );
            }
        }

        if ((1000/fps) > SDL_GetTicks() - starting_tick) { // ----------- Limit the frame per second to 60
            SDL_Delay( 1000/fps - (SDL_GetTicks() - starting_tick));
        }
    }


    // 4º Destroy window / terminate sdl process
    SDL_DestroyWindow(window); // --------------------------------------- Delete window
    SDL_Quit(); // ------------------------------------------------------ Terminate SDL functions


    return 0;
}