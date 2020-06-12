#pragma once

#include "group.h"
#include "eventlistener.h"

namespace Zengine{
class Image;
class Button: public Group, public EventListener{
public:
  Button(const std::string& tex);
  virtual void onEvent(Event* event);
  
protected:
  Image* image;
  Rect touchArea;
};
}