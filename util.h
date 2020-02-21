#pragma once

#include "stdafx.h"

namespace Zengine{
class SimpleRand{
public:
  SimpleRand(int min, int max);
  SimpleRand();
  
  int getIntRnd();
  double getDoubleRnd();
protected:
  boost::random::mt19937 _randEngine;
  boost::random::uniform_int_distribution<> _rndInt;
  boost::random::uniform_real_distribution<> _rndDouble;
};

class Random{
	static Random* _inst;
	static Random* inst();

	Random();
public:
	static float Float(float begin, float end);
	static float Float(float end);
	static float Float();
	static float random();
	static int Int(int begin, int end);
	static int IntRange(int begin, int end);
	static int NormalIntRange(int min, int max);
	static int Int(int end);
};

class Utils{
public:
	static const float POINTF_PI;
	static const float POINTF_PI2;
	static const float POINTF_G2R;
	static const float G2RAD;
public:
  static Rect rect(int x, int y, int w, int h);
	static float speed(float speed, float acc);
	static void MATRIXRotate(Matrix& mat, float angle);
	static void MATRIXScale(Matrix& mat, float sx, float sy);
	static void MATRIXSkewX(Matrix& mat, float a);
};

}
