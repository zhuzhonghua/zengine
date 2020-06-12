#pragma once

namespace Zengine{
class EventListener;
class Event;

class ListenerManager{
protected:
  static std::vector<EventListener*> listeners;
  static std::map<int, Event*> pointers;
  static bool canceled;
	static bool touched;

  static void dispatch(Event* event);
public:
  static void add(EventListener* listener);
  static void remove(EventListener* listener);

  static void processEvents(std::vector<SDL_Event>& events);
  static void cancel();
};
}