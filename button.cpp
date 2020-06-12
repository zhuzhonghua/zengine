#include "zengine.h"
#include "button.h"
#include "image.h"
#include "util.h"
#include "camera.h"

using namespace Zengine;

Button::Button(const std::string& tex)
{
	image = new Image(tex);
	add(image);

	touchArea = image->getDstRect();
}

void Button::onEvent(Event* event)
{
	if (event != NULL) 
	{
		Point point = camera()->screenToWorld(event->current);
		bool hit = Utils::overlapPoint(touchArea, point);

		if (hit)
		{
			printf("hit %d\n", hit);
		}
	}
}