#include <SDL3/SDL.h>
#include <GL/glew.h>
#include <iostream>

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) <= 0) {
        std::cerr << "SDL Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("OpenGL Window",
                                          800, 600,
                                          SDL_WINDOW_OPENGL);
    if (!window) {
        std::cerr << "SDL CreateWindow Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext) {
        std::cerr << "OpenGL Context Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to init GLEW\n";
        return 1;
    }

    bool running = true;
    SDL_Event event;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                running = false;
            }
        }

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(window);
    }

    SDL_GL_DestroyContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
