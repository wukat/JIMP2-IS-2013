#ifndef PYRAMID_H
#define PYRAMID_H
#include "Block.h"
#include "Floor.h"

using namespace std;

class Pyramid
{
private:
  int height;
  list<Floor> floors;

public:
  Pyramid();
  Pyramid(int);
  Pyramid(const Pyramid &);
  ~Pyramid();

  Floor getf(int);
  Block get(int, int);
  void color_set(int, int);
  void set(int, int, int);
  void show();
};

#endif
