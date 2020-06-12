#pragma once

namespace Zengine{

// TODO: 支持其他交互，除了点击和滑动
struct Event{
  Event(SDL_Event* e);

  void update(SDL_Event* e);
  Event* up();

  Point start;
  Point current;

	bool down;
};

class EventListener;
typedef void (*OnEvent)(EventListener* listener);

class EventListener{
public:
  EventListener();
  ~EventListener();
  virtual void onEvent(Event* event) = 0;
};
}