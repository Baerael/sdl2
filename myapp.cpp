#include <stdio.h>
#include <iostream>
// opengl
#include <GL/glew.h>
// sdl
#include <SDL2/SDL.h>

#define SCREEN_SIZE_X 800 
#define SCREEN_SIZE_Y 600

int main() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "SDL couldNOTTTT not initialize\n");
        return 1;
    }

    // Create window
    SDL_Window* window = SDL_CreateWindow("My Game", 
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 
        SCREEN_SIZE_X, SCREEN_SIZE_Y, SDL_WINDOW_OPENGL | 
        SDL_WINDOW_SHOWN);
    if (!window) {
        fprintf(stderr, "Error craeting window.\n");
        return 2;
    }

    // SDL Opengl settings
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);

    // SDL OpenGL context
    SDL_GLContext glContext = SDL_GL_CreateContext(window);

    // SDL v-sync
    SDL_GL_SetSwapInterval(1);

    // GLEW
    glewInit();
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Surface
    SDL_Surface* screenSurface = NULL;



    // Square
    //SDL_Rect rect = {0, 0, 100, 100}; // x, y, width, height

    // Game loop
    bool quit = false;
    while (quit == false) {
        SDL_Event windowEvent;
        while(SDL_PollEvent(&windowEvent)) {
            if (windowEvent.type == SDL_QUIT) {
                quit = true;
                break;
            }
        }
        // animations
        screenSurface = SDL_GetWindowSurface(window);
        SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format,0xAA,0xFF,0xFF));
        SDL_UpdateWindowSurface(window);

       glClear(GL_COLOR_BUFFER_BIT);
        //SDL_GL_SwapWindow(window);
    }

    // Clean up
    SDL_GL_DeleteContext(glContext);

    return 0;
}
























