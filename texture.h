#pragma once

struct SDL_Surface;

namespace Zengine{
class Texture{
public:
	Texture();
	Texture(const std::string& bitmap);
	Texture(SDL_Surface* img);
	virtual ~Texture();

	void destroy();

	virtual void bitmap(const std::string& bitmap);
	virtual void bitmap(SDL_Surface* img);

	//static Texture* create(int width, int height, std::vector<byte> data);

	int getPixel(int x, int y);
	void setPixel(int x, int y, int color);

	SDL_Texture* getTex() { return tex; }
protected:
	int width;
	int height;

	SDL_Surface* texSrc;
	SDL_Texture* tex;
};
}
