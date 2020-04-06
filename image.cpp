#include "stdafx.h"

#include "image.h"
#include "texturecache.h"
#include "util.h"
#include "graphic.h"

using namespace Zengine;

Image::Image() :Visual(0,0,0,0)
{
	init();
}

Image::Image(const Image& other):Visual(0,0,0,0)
{
	init();
	copy(other);
}

Image::Image(const Image* other):Visual(0,0,0,0)
{
	init();
	copy(*other);
	delete other;
}

Image::Image(SmartTexture* other):Visual(0,0,0,0)
{
	init();

	tex = other;
	// TODO: 
	//frame(Utils::rect(0, 0, 1, 1));
}
//// TODO: coordinate
//Image::Image(const std::string& tx, int left, int top, int width, int height) : Image(tx)
//{
//	frame(tex->uvRect(left,top,left+width,top+height));
//}

Image::Image(const std::string& tx):Visual(0,0,0,0)
{
	init();
	texture(tx);
}

void Image::init()
{
	flipVertical = false;
	flipHorizontal = false;
}

void Image::texture(const std::string& tx)
{
	tex = TextureCache::getTexture(tx);
	frame(Utils::rect(0, 0, 1, 1));
}

void Image::texture(SmartTexture* tx)
{
	tex = tx;
	frame(Utils::rect(0, 0, 1, 1));
}

void Image::copy(const Image& other)
{
	// TODO: depth copy problem
	tex = other.tex;

	_frame = other._frame;
	
	width = other.width;
	height = other.height;

	updateFrame();
	updateVertices();
}

void Image::frame(const Rect& frame)
{
	this->_frame = frame;

	// TODO: 
	//width = GameMath::RECTFWidth(frame) * tex->width;
	//height = GameMath::RECTFHeight(frame) * tex->height;
	
	updateFrame();
	updateVertices();
}

//void Image::frame(int left, int top, int width, int height)
//{
//	frame(tex->uvRect(left, top, left + width, top + height));
//}

void Image::draw()
{
	Graphic::renderCopy(this, NULL, NULL);
//
//	Visual::draw();
//	
//	NoosaScript* script = NoosaScript::get();
//	
//	tex->bind();
//	script->camera(camera());
//	
//	script->uModel.valueM4(_mat);
//	script->lighting(
//		rm,gm,bm,am,
//		ra,ga,ba,aa);
//	
//	// TODO: check dirty, optimization
//	script->drawQuad(&_vertices[0]);
//	//float vertices[] = { 0, 0, _vertices[2], _vertices[3],
//	//					 1, 0, _vertices[6], _vertices[7],
//	//					 1, 1, _vertices[10], _vertices[11],
//	//					 0, 1, _vertices[14], _vertices[15] };
//	//script->drawQuad(vertices);
}

void Image::updateVertices()
{
}

void Image::updateFrame()
{
}
