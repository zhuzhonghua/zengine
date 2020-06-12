#pragma once

#include <SDL.h>

static inline void fatalError(std::string info)
{
  std::cout << info << std::endl;
  //std::cout << "Enter Any Key To Exit" << std::endl;
  //int tmp;
  //std::cin >> tmp;
  SDL_Quit();
  exit(1);
}

typedef SDL_Rect Rect;
typedef SDL_Point Point;

#define INT_MAX_VALUE 0x3FFFFFFF
