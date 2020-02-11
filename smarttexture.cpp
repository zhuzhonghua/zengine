#include "stdafx.h"

#include "smarttexture.h"
#include "util.h"
#include "texturecache.h"

using namespace Zengine;

RectF SmartTexture::uvRect(int left, int top, int right, int bottom)
{
	return GameMath::RECTF(
		(float)left / width,
		(float)top / height,
		(float)right / width,
		(float)bottom / height);
}

void SmartTexture::bitmap(const std::string& bp)
{
	Texture::bitmap(bp);

	this->bitmaps = bp;
}

SmartTexture::SmartTexture(SDL_Surface* img)
{
	Texture::bitmap(img);
}

SmartTexture::SmartTexture(const std::string& bp)
{
	bitmap(bp);
}

Gradient::Gradient(std::vector<int> colors)
:SmartTexture(TextureCache::createSurface(colors.size(), 1, 0))
{
	for (int i = 0; i < colors.size(); i++) {
		setPixel(i, 0, colors[i]);
	}
	Texture::bitmap(texSrc);

	TextureCache::add<Gradient>(this);
}
