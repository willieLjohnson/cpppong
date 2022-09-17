#include "vec.cpp"
#include <SDL2/SDL.h>

const int PADDLE_WIDTH = 10;
const int PADDLE_HEIGHT = 60;

class Paddle {
public:
  Vec2 position;
  SDL_Rect rect{};

  Paddle(Vec2 position) : position(position) {
    rect.x = static_cast<int>(position.x);
    rect.y = static_cast<int>(position.y);
    rect.w = PADDLE_WIDTH;
    rect.h = PADDLE_HEIGHT;
  }

  void Draw(SDL_Renderer *renderer) {
    rect.y = static_cast<int>(position.y);
    SDL_RenderFillRect(renderer, &rect);
  }
};
