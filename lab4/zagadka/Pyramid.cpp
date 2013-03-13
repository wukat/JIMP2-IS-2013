#include "Pyramid.h"

using namespace std;

Pyramid::Pyramid():height(0)
{}

Pyramid::Pyramid(int height)
{
  this->height = height;
  for (int i = 1; i <= height; i++)
    floors.push_back(Floor(i));
}

Pyramid::~Pyramid()
{
  floors.clear();
}

Pyramid::Pyramid(const Pyramid & other)
{
  for (list<Floor>::const_iterator iter = other.floors.begin(); iter != other.floors.end(); ++iter)
    floors.push_back(*iter);
}

Floor Pyramid::getf(int level)
{
  int i = 0;
  for (list<Floor>::iterator iter = floors.begin(); iter != floors.end() && i < level; ++iter, i++)
    if (i == level - 1)
      return *iter;
}

Block Pyramid::get(int level, int index)
{
  return getf(level).get(index);
}

void Pyramid::color_set(int level, int color)
{
  getf(level).setcolor(color);
}

void Pyramid::set(int level, int index, int number)
{
  int i = 0;
  for (list<Floor>::iterator iter = floors.begin(); iter != floors.end() && i < level; ++iter, i++)
    if (i == level - 1)
      iter->set(index, number);
}

void Pyramid::show()
{
  int i = 1;
  for (list<Floor>::iterator iter = floors.begin(); iter != floors.end(); ++iter, i++)
  {
    for (int j = 0; j < height - i; j++)
      cout << " ";
    iter->show();
    cout << endl;
  }
}
