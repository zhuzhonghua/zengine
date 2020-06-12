#include "zengine.h"
#include "util.h"
#include "camera.h"

using namespace Zengine;

SimpleRand::SimpleRand()
  :_rndDouble(0, 1)
{
}

SimpleRand::SimpleRand(int min, int max)
  :_rndInt(min, max)
{
}

double SimpleRand::getDoubleRnd()
{
  return _rndDouble(_randEngine);
}

int SimpleRand::getIntRnd()
{
  return _rndInt(_randEngine);
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