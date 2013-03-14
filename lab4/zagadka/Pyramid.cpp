#include "Pyramid.h"
#include <cstdlib>

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

int Pyramid::get(int level, int index)
{
  return getf(level).get(index);
}

void Pyramid::color_set(int level, int color)
{
  int i = 0;
  for (list<Floor>::iterator iter = floors.begin(); iter != floors.end() && i < level; ++iter, i++)
    if (i == level - 1)
      iter->setcolor(color);
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

void Pyramid::fill(int help1, int help2, bool & done, int level, int index)
{
  int help3;
  if ((help3 = abs(help1 - help2)) > 0 && help3 <= 9)
  {
    set(level, index, help3);
    if (check_floor(level) && check_oth(level, index))
    {
      if (!solve_pyramid()) set(level, index, 0);
      else done = 1;
    }
    else
      set(level, index, 0); 
  }
  if (done == 0 && (help3 = help1 + help2) > 0 && help3 <= 9)
  {
    set(level, index, help3);
    if (check_floor(level) && check_oth(level, index))
    { 
      if (!solve_pyramid()) set(level, index, 0);
      else done = 1;
    }
    else
    set(level, index, 0); 
  }
}

bool Pyramid::try_to_complete()
{
  bool done = 0;
  bool done1 = 0;
  int help1, help2;
  for (int level = height; level >= 1; level--)
  {
    for (int index = 1; index <= level; index++)
    {
      if (done == 0 && done1 == 0 && get(level, index) == 0) 
      {  
        if (level < height && (help1 = get(level + 1, index)) > 0 && (help2 = get(level + 1, index + 1)) > 0)
        {
          done1 = 1;
          fill(help1, help2, done, level, index);
        } 
        if (done == 0 && level > 1 && index < level && (help1 = get(level - 1, index)) > 0 && (help2 = get(level, index + 1)) > 0)
        {  
          done1 = 1;
          fill(help1, help2, done, level, index);
        }
        if (done == 0 && level > 1 && index > 1 && (help1 = get(level - 1, index - 1)) > 0 && (help2 = get(level, index - 1)) > 0)
        {
          done1 = 1;
          fill(help1, help2, done, level, index);
        }
      } 
    }
  }
  return done;
}

bool Pyramid::solve_pyramid()
{
  bool ok;
  if ((ok = is_done())) show();
  else ok = try_to_complete();
  return ok;
}

bool Pyramid::is_done()
{
  bool done = true;
  for (int i = height; i >= 1; i--)
  {
    if (!check_floor(i)) done = false;
    for (int j = 1; j <= i; j++)
    {
      if (get(i, j) == 0) 
      {
        done = false;
      }
      else if (!check_block(i,j)) done = false;
    }
  }
 
  return done;
}

bool Pyramid::check_floor(int i)
{
  return getf(i).check(); 
}

bool Pyramid::check_block(int level, int index)
{
  bool ok = true;
  int help1, help2, help3 = get(level, index);
  if (level < height)
  {
    help1 = get(level + 1, index);
    help2 = get(level + 1, index + 1);
    if (!(help3 == help1 + help2 || help1 == help2 + help3 || help2 == help1 + help3)) ok = false;
  }
  if (level > 1 && index < level)
  {
    help1 = get(level - 1, index);
    help2 = get(level, index + 1);
    if (!(help3 == help1 + help2 || help1 == help2 + help3 || help2 == help1 + help3)) ok = false;
  }
  if (level > 1 && index > 1)
  {
    help1 = get(level - 1, index - 1);
    help2 = get(level, index - 1);
    if (!(help3 == help1 + help2 || help1 == help2 + help3 || help2 == help1 + help3)) ok = false;
  }
  return ok;
}

bool Pyramid::check_oth(int level, int index)
{
  bool ok = true;
  int help1, help2, help3 = get(level, index);
  if (level < height)
  {
    help1 = get(level + 1, index);
    help2 = get(level + 1, index + 1);
    if (help1 != 0 && help2 != 0 && !(help3 == help1 + help2 || help1 == help2 + help3 || help2 == help1 + help3)) ok = false;
  }
  if (level > 1 && index < level)
  {
    help1 = get(level - 1, index);
    help2 = get(level, index + 1);
    if (help1 != 0 && help2 != 0 && !(help3 == help1 + help2 || help1 == help2 + help3 || help2 == help1 + help3)) ok = false;
  }
  if (level > 1 && index > 1)
  {
    help1 = get(level - 1, index - 1);
    help2 = get(level, index - 1);
    if (help1 != 0 && help2 != 0 && !(help3 == help1 + help2 || help1 == help2 + help3 || help2 == help1 + help3)) ok = false;
  }
  return ok;
}
