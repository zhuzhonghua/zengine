#pragma once

#include "texture.h"

namespace Zengine{
class SmartTexture :public Texture{
public:
	std::string bitmaps; 

	SmartTexture(SDL_Surface* img);
	SmartTexture(const std::string& bitmap);

	RectF uvRect(int left, int top, int right, int bottom);

	virtual void bitmap(const std::string& bitmap);
};

class Gradient :public SmartTexture{
public:
	Gradient(std::vector<int> colors);
};
};
