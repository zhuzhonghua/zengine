#pragma once

#include <map>
#include <string>
#include "texture.h"

struct SDL_PixelFormat;

namespace Zengine{
class TextureCache
{
protected:
	static TextureCache* _inst;
	
	static TextureCache* inst();
	TextureCache();
public:	
	~TextureCache();

	static Texture* getTexture(std::string);
	static Texture* createSolid(int color);
	static Texture* createSolid(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
	//static SDL_Surface* createSurface(int w, int h,int argb);

	static bool contains(const std::string& key);

	static void add(const std::string& key, Texture* tx)
	{
		inst()->_texMap.insert(std::make_pair(key, tx));
	}

	static SDL_PixelFormat* getPixelFormat() { return inst()->_pixelFormat; }
private:
	std::map<std::string, Texture*> _texMap;
	SDL_PixelFormat*	_pixelFormat;
};
}