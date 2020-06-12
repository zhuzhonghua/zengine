#pragma once

#include "gizmo.h"
#include "SDL_ttf.h"

namespace Zengine{
class Texture;
class BitmapText : public Gizmo{
public:
	BitmapText(const std::string& text);

	std::string text() {return str;}
	void text(const std::string& text);

	virtual void draw();
protected:
	static TTF_Font* font;

	std::string str;
	Texture* tex;
	Rect rect;
};
}