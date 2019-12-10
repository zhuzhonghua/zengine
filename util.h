#pragma once

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

class Utils{
public:
  static Rect rect(int x, int y, int w, int h);
};
