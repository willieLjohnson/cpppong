#include "ball.cpp"
#include "paddle.cpp"
#include <SDL2/SDL.h>

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

int main() {
  // Initialize SDL components
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow("Pong", 0, 0, WINDOW_WIDTH,
                                        WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

  Ball ball(Vec2((WINDOW_WIDTH / 2.0f) - (BALL_WIDTH / 2.0f),
                 (WINDOW_HEIGHT / 2.0f) - (BALL_WIDTH / 2.0f)));
  Paddle paddleOne(
      Vec2(50.0f, (WINDOW_HEIGHT / 2.0f) - (PADDLE_HEIGHT / 2.0f)));
  Paddle paddleTwo(Vec2(WINDOW_WIDTH - 50.0f,
                        (WINDOW_HEIGHT / 2.0f) - (PADDLE_HEIGHT / 2.0f)));
  // Game logic
  {
    bool running = true;

    // Continue looping and processing events until user exits
    while (running) {
      SDL_Event event;
      while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT) {
          running = false;
        } else if (event.type == SDL_KEYDOWN) {
          if (event.key.keysym.sym == SDLK_ESCAPE) {
            running = false;
          }
        }
      }
      // Clear the window to black
      SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
      SDL_RenderClear(renderer);

      // Set the draw color to be white
      SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

      // Draw the net
      for (int y = 0; y < WINDOW_HEIGHT; ++y) {
        if (y % 5) {
          SDL_RenderDrawPoint(renderer, WINDOW_WIDTH / 2, y);
        }
      }

      // Draw ball
      ball.Draw(renderer);

      // Draw paddles
      paddleOne.Draw(renderer);
      paddleTwo.Draw(renderer);

      // Present the backbuffer
      SDL_RenderPresent(renderer);
    }
  }

  // Cleanup
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
