#pragma once
#include <boost/random.hpp>
#include "simpledefine.h"
#include <stdlib.h>

namespace Zengine{
class IntRand{
public:
  IntRand(int minInclude, int maxExclude);
  
  int getInt();
protected:
  int min;
  int max;
};

class DoubleRand{
public:
  DoubleRand();
  
  double getDouble();
};

class Utils{
public:
  static Rect rect(int x, int y, int w, int h);

  //static bool overlapScreenPoint(Gizmo* gizmo, Rect rect, Point p);
  static bool overlapPoint(const Rect& rect, const Point& p);
};
};