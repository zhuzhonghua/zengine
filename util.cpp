#include "zengine.h"
#include "util.h"
#include "camera.h"

using namespace Zengine;

IntRand::IntRand(int minInclude, int maxExclude)
  :min(minInclude), max(maxExclude)
{
}

int IntRand::getInt()
{
  return (rand() % (max-min))+ min;
}

DoubleRand::DoubleRand()
{
}

double DoubleRand::getDouble()
{
  return rand() / double(RAND_MAX);
}


Rect Utils::rect(int x, int y, int w, int h)
{
  Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;

  return rect;
}

bool Utils::overlapPoint(const Rect& rect, const Point& p)
{
  return p.x >= rect.x && p.x < rect.x + rect.w && p.y >= rect.y && p.y < rect.y + rect.h;
}