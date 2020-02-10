#pragma once

#include "signal.h"

namespace Zengine{
class TouchScreen{
public:
	class Touch {
	public:
		PointF start;
		PointF current;
		bool down;

		Touch(SDL_Event* e, int index);
		void update(SDL_Event* e, int index);
		Touch* up();
	};

	static Signal<Touch> event;

	static std::map<int, Touch*> pointers;

	static float x;
	static float y;
	static bool touched;

	static void processTouchEvents(std::vector<SDL_Event>& events);
};
}
