#include "zengine.h"
#include "texturecache.h"

using namespace Zengine;

TextureCache* TextureCache::_inst;

TextureCache* TextureCache::inst()
{
	if (_inst == NULL)
	{
		_inst = new TextureCache();
	}

	return _inst;
}

TextureCache::TextureCache()
{
	_pixelFormat = SDL_AllocFormat(SDL_PIXELFORMAT_RGBA8888);
}

TextureCache::~TextureCache()
{
	SDL_FreeFormat(_pixelFormat);
}

Texture* TextureCache::getTexture(std::string texPath)
{
	TextureCache* tc = inst();
	std::map<std::string, Texture*>::iterator mit = tc->_texMap.find(texPath);
	if (mit == tc->_texMap.end())
	{
		Texture* tex = new Texture(texPath);
		tc->_texMap.insert(std::make_pair(texPath, tex));
		return tex;
	}

	return mit->second;
}

Texture* TextureCache::createSolid(int color)
{
	char tmp[32] = { 0 };
	sprintf(tmp, "1x1:%d", color);

	TextureCache* tc = inst();
	std::map<std::string, Texture*>::iterator mit = tc->_texMap.find(tmp);
	if (mit != tc->_texMap.end())
	{
		return mit->second;
	}
	else 
	{
		Uint32 rmask, gmask, bmask, amask;
#if SDL_BYTEORDER == SDL_BIG_ENDIAN
		rmask = 0xff000000;
		gmask = 0x00ff0000;
		bmask = 0x0000ff00;
		amask = 0x000000ff;
#else
		rmask = 0x000000ff;
		gmask = 0x0000ff00;
		bmask = 0x00ff0000;
		amask = 0xff000000;
#endif

		SDL_Surface* img = SDL_CreateRGBSurface(0, 1, 1, 32, rmask, gmask, bmask, amask);
		SDL_FillRect(img, NULL, color);

		Texture* tex = new Texture(img);
		tc->_texMap.insert(std::make_pair(tmp, tex));

		//SDL_FreeSurface(img);

		return tex;
	}
}

Texture* TextureCache::createSolid(Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
	return createSolid(SDL_MapRGBA(getPixelFormat(), r, g, b, a));
}

bool TextureCache::contains(const std::string& key)
{
	return inst()->_texMap.find(key) != inst()->_texMap.end();
}