#include "zengine.h"
#include "listenermanager.h"
#include "eventlistener.h"

using namespace Zengine;

std::vector<EventListener*> ListenerManager::listeners;
std::map<int, Event*> ListenerManager::pointers;
bool ListenerManager::touched;
bool ListenerManager::canceled;

void ListenerManager::add(EventListener* listener)
{
  std::vector<EventListener*>::iterator itr = std::find(listeners.begin(), listeners.end(), listener);  
	if (itr == listeners.end())
  {
    listeners.push_back(listener);
  }  
}

void ListenerManager::remove(EventListener* listener)
{
  std::vector<EventListener*>::iterator itr = std::find(listeners.begin(), listeners.end(), listener);  
	if (itr != listeners.end())
	{
		listeners.erase(itr);
	}
}

void ListenerManager::dispatch(Event* event)
{
  canceled = false;

  for (int i = 0; i < listeners.size(); i++) 
	{
		EventListener* listener = listeners[i];

		listener->onEvent(event);
		if (canceled) 
		{
			return;
		}
	}
}

void ListenerManager::processEvents(std::vector<SDL_Event>& events)
{
  for (int i = 0; i < events.size(); i++)
  {
    SDL_Event& e = events[i];

    switch (e.type)
    {
    case SDL_MOUSEBUTTONDOWN:
      {
        touched = true;
        // TODO：多个手指点击
        Event* event = new Event(&e);
        pointers.insert(std::make_pair(0, event));
        dispatch(event);
      }
      break;
    case SDL_MOUSEBUTTONUP:
      {
        touched = false;
        std::map<int, Event*>::iterator itr = pointers.find(0);
        if (itr != pointers.end())
        {
          Event* event = itr->second;
          pointers.erase(itr);
          event->up();
          dispatch(event);
          delete itr->second;
        }
      }
      break;
    case SDL_MOUSEMOTION:
      {
        std::map<int, Event*>::iterator itr = pointers.find(0);
        if (itr != pointers.end())
        {
          Event* event = itr->second;
          event->update(&e);          
        }
        dispatch(NULL);
      }
      break;
    }
  }
}

void ListenerManager::cancel()
{
	canceled = true;
}