#include "core.hpp"

// Start
Core::Core(const std::string title, int width, int height)
    : windowTitle(title), screenWidth(width), screenHeight(height) {
  initSDL();
  initWindow();
  initGlContext();
  initGlew();
}

void Core::initSDL() {
  if (SDL_Init(SDL_INIT_VIDEO) <= 0) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR,
                 "[Error] SDL initialization failed: %s", SDL_GetError());
  } else {
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                "[Init] SDL initialized successfully");
  }
}

void Core::initWindow() {
  window = SDL_CreateWindow(windowTitle.c_str(), screenWidth, screenHeight,
                            SDL_WINDOW_OPENGL);

  if (!window) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "[Error] Window creation failed: %s ",
                 SDL_GetError());
  } else {
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                "[Init] Window created successfully (%dx%d)", screenWidth,
                screenHeight);
  }
}

void Core::initGlContext() {
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

  glContext = SDL_GL_CreateContext(window);
  if (!glContext) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR,
                 "[Error] OpenGL Context creation failed: %s ", SDL_GetError());
  } else {
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                "[Init] OpenGL Context created successfully");
  }
}

void Core::initGlew() {

  GLenum err = glewInit();
  if (glewInit() != GLEW_OK) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR,
                 "[Error] GLEW initialization failed: %s",
                 (const char *)glewGetErrorString(err));
  } else {
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                "[Init] GLEW initialized successfully");
  }
}

// Update
bool Core::windowClose(SDL_Event &e) {
  while (SDL_PollEvent(&e)) {
    if (e.type == SDL_EVENT_QUIT) {
      SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION, "[Event] Quit event received");
      return true;
    }
    return false;
  }
  return false;
}

// End
void Core::destroyWindow() {
  if (window) {
    SDL_DestroyWindow(window);
    SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
                "[Destroy] Window destroyed successfully");
    window = nullptr;
  }
}

void Core::destroyGlContext() {
  if (glContext) {
    SDL_GL_DestroyContext(glContext);
    SDL_LogInfo(SDL_LOG_CATEGORY_RENDER,
                "[Destroy] OpenGL Context destroyed successfully");
    glContext = nullptr;
  }
}

Core::~Core() {
  destroyGlContext();
  destroyWindow();
  SDL_Quit();
  SDL_LogInfo(SDL_LOG_CATEGORY_APPLICATION,
              "[Exit] SDL quit and resources cleaned up");
}
