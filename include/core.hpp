#pragma once
#include <GL/glew.h>
#include <SDL3/SDL.h>
#include <string>

class Core {
public:
  SDL_Window *window = nullptr;
  SDL_GLContext glContext = nullptr;

  float deltaTime;

  Core(const std::string, int width, int height);
  ~Core();

  // Update
  bool windowClose(SDL_Event &e);

private:
  const int screenWidth;
  const int screenHeight;
  const std::string windowTitle;

  // Start
  void initSDL();
  void initWindow();
  void initGlContext();
  void initGlew();

  // End
  void destroyWindow();
  void destroyGlContext();
};
