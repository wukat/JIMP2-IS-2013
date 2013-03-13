#ifndef FLOOR_H
#define FLOOR_H
#include "Block.h"
#include <list>

using namespace std;

class Floor
{
public:
  Floor();
  Floor(int);
  ~Floor();
  Floor(const Floor &);

  Block get(int);
  void set(int, int);
  void setcolor(int);
  void show();

private:
  list<Block> content;
  int length;
  int color;
};

#endif
