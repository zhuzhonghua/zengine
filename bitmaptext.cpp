#include "zengine.h"

#include "bitmaptext.h"
#include "game.h"
#include "texture.h"

using namespace Zengine;

TTF_Font* BitmapText::font = NULL;

BitmapText::BitmapText(const std::string& t)
{	
	tex = NULL;
	if (font == NULL)
	{
		font = TTF_OpenFont("data/msyhbd.ttf", 32);

		if (!font) fatalError("fail open font");
	}

	text(t);
}

void BitmapText::text(const std::string& t)
{
	if (t.length() <= 0) return;

	const SDL_Color c = { 255, 255, 255};

	str = t;
	SDL_Surface* surface = TTF_RenderUTF8_Blended(font, t.c_str(), c);
	if (tex == NULL)
	{
		tex = new Texture(surface);
	}
	else
	{
		tex->bitmap(surface);
	}

	int w = 0, h = 0;
	TTF_SizeUTF8(font, str.c_str(), &w, &h);
	rect.w = w;
	rect.h = h;

	rect.x = 100;
	rect.y = 100;
}

void BitmapText::draw()
{
	Gizmo::draw();

	SDL_RenderCopy(Game::inst()->getRender(), tex->getTex(), NULL, &rect);
}