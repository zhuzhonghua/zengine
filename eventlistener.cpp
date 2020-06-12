#include "zengine.h"
#include "listenermanager.h"
#include "eventlistener.h"

using namespace Zengine;

EventListener::EventListener()
{
  ListenerManager::add(this);
}

EventListener::~EventListener()
{
  ListenerManager::remove(this);
}

Event::Event(SDL_Event* e)
{
  float x = e->motion.x;
	float y = e->motion.y;

	start.x = x;
	start.y = y;

	current = start;

	down = true;
}

void Event::update(SDL_Event* e)
{
  //current.set(e.getX(index), e.getY(index));
	float x = e->motion.x;
	float y = e->motion.y;

	current.x = x;
	current.y = y;
}

Event* Event::up()
{
  down = false;
  return this;
}