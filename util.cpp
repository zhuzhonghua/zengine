#include "stdafx.h"
#include "util.h"
#include "game.h"

using namespace Zengine;

SimpleRand::SimpleRand()
  :_rndDouble(0, 1)
{
}

SimpleRand::SimpleRand(int min, int max)
  :_rndInt(min, max)
{
}

double SimpleRand::getDoubleRnd()
{
  return _rndDouble(_randEngine);
}

int SimpleRand::getIntRnd()
{
  return _rndInt(_randEngine);
}


Random* Random::_inst;

Random::Random()
{
	srand(time(NULL));
}

Random* Random::inst()
{
	if (_inst == NULL)
	{
		_inst = new Random();
	}

	return _inst;
}

float Random::Float(float begin, float end)
{
	return begin + random()*(end - begin);
}

float Random::Float(float end)
{
	return random()*end;
}

float Random::Float()
{
	return Float(0, 1);
}

float Random::random()
{
	int rnd = rand() % 65535;
	//return Float(0, 1);
	return rnd / 65535.0f;
}

int Random::Int(int begin, int end)
{
	return begin + (int)(random()*(end - begin));
}

int Random::Int(int end)
{
	if (end > 0)
	{
		return (int)(random()*end);
	}
	else
	{ 
		return 0;
	}
}

int Random::IntRange(int begin, int end)
{
	return begin + (int)(random()* (end - begin + 1));
}

Rect Utils::rect(int x, int y, int w, int h)
{
  Rect rect;
  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;

  return rect;
}

float Utils::speed(float speed, float acc)
{
	if (acc != 0) 
	{
		speed += acc * Game::elapsed;
	}

	return speed;
}

/*
[m00 m01] [cos -sin]
[m10 m11] [sin  cos]
*/
void Utils::MATRIXRotate(Matrix& mat, float angle)
{
	angle = angle * 3.14f / 180.0f;
	float s = sin(angle);
	float c = cos(angle);

	float m0 = mat[0][0];
	float m1 = mat[0][1];
	float m4 = mat[1][0];
	float m5 = mat[1][1];

	mat[0][0] = m0 * c + m4 * s;
	mat[0][1] = m1 * c + m5 * s;
	mat[1][0] = -m0 * s + m4 * c;
	mat[1][1] = -m1 * s + m5 * c;
}

void Utils::MATRIXScale(Matrix& m, float x, float y)
{
	m[0][0] *= x;
	m[0][1] *= x;
	m[0][2] *= x;
	m[0][3] *= x;
	m[1][0] *= y;
	m[1][1] *= y;
	m[1][2] *= y;
	m[1][3] *= y;
}

const float Utils::POINTF_PI = 3.1415926f;
const float Utils::POINTF_PI2 = Utils::POINTF_PI * 2;
const float Utils::POINTF_G2R = Utils::POINTF_PI / 180;
const float Utils::G2RAD = 0.01745329251994329576923690768489f;
void Utils::MATRIXSkewX(Matrix& mat, float a)
{
	double t = std::tan(a * G2RAD);
	//m[4] += -m[0] * t;
	//m[5] += -m[1] * t;

	mat[1][0] += -mat[0][0] * t;
	mat[1][1] += -mat[0][1] * t;
}
