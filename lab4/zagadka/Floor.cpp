#include "Floor.h"

Floor::Floor():length(0)
{}

Floor::Floor(int length)
{
  this->length = length;
  for (int i = 1; i <= length; i++)
    content.push_back(Block());
}

Floor::~Floor()
{
  content.clear();
}

Floor::Floor(const Floor &other)
{
  for (list<Block>::const_iterator iter = other.content.begin(); iter != other.content.end(); ++iter)
    content.push_back(*iter);
}

Block Floor::get(int n)
{
  int i = 0;
  for (list<Block>::iterator iter = content.begin(); iter != content.end() && i < n; ++iter, i++)
    if (i == n - 1)
      return *iter;
}

void Floor::set(int n, int number)
{
  int i = 0;
  for (list<Block>::iterator iter = content.begin(); iter != content.end() && i < n; ++iter, i++)
    if (i == n - 1)
      iter->setn(number);
}

void Floor::setcolor(int color)
{
  this->color = color;
}

void Floor::show()
{
  for (list<Block>::iterator iter = content.begin(); iter != content.end(); ++iter)
    iter->show();
}




