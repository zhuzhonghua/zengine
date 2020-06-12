#include "zengine.h"

#include "image.h"
#include "texturecache.h"
#include "util.h"
#include "game.h"
#include "camera.h"

using namespace Zengine;

Image::Image(const std::string& tx)
{
	texture(tx);
	init();
}

Image::Image(Texture* tx)
{
	tex = tx;
	init();
}

void Image::init()
{
	dst.x = 100;
	dst.y = 100;
	dst.w = 100;
	dst.h = 100;
}

void Image::setRect(const Rect& rect)
{
	dst = rect;
}

void Image::setPos(int x, int y)
{
	dst.x = x;
	dst.y = y;
}

void Image::texture(const std::string& tx)
{
	tex = TextureCache::getTexture(tx);
}

void Image::draw()
{
	SDL_Rect dstCamera = Camera::getMain()->worldToScreen(dst);
	SDL_RenderCopy(Game::inst()->getRender(), tex->getTex(), NULL, &dstCamera);
}
