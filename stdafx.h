#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include <map>
#include <set>
#include <vector>
#include <list>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <boost/random.hpp>

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

static inline void fatalError(std::string info)
{
  std::cout << info << std::endl;
  std::cout << "Enter Any Key To Exit" << std::endl;
  int tmp;
  std::cin >> tmp;
  SDL_Quit();
  exit(1);
}

typedef SDL_Rect Rect;
typedef SDL_Point Point;


typedef glm::vec2 PointF;
typedef glm::ivec2 Point;
typedef glm::mat4 Matrix;
typedef glm::vec4 RectF;
typedef glm::ivec4 Rect;

typedef unsigned char byte;
typedef unsigned short Uint16;

#define INT_MAX_VALUE 0x3FFFFFFF

