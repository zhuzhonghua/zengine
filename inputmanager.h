#pragma once

#include <map>
#include "util.h"

namespace Zengine{
class InputManager{
public:
  InputManager();

  void update();

  void pressKey(unsigned int key);
  void releaseKey(unsigned int key);

  bool isKeyDown(unsigned int key);
  bool isKeyPressed(unsigned int key);

  void setMouseCoords(float x, float y);

  Point getMouseCoords() const { return _mouseCoords; }
private:
  bool wasKeyDown(unsigned int key);

  std::map<unsigned int, bool> _keys;
  std::map<unsigned int, bool> _previousKeys;

  Point _mouseCoords;
};
};
