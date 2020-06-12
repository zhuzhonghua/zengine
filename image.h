#pragma once

#include "gizmo.h"

#include <string>

namespace Zengine{
class Texture;
class Image :public Gizmo{
public:
	Image(const std::string& tx);
	Image(Texture* tx);

	void texture(const std::string& tx);

	virtual void draw();

	void setRect(const Rect& rect);
	void setPos(int x, int y);

	Rect getDstRect() { return dst; }
	
protected:
	void init();
protected:

	Texture* tex;
	Rect src;
	Rect dst;
};
};
