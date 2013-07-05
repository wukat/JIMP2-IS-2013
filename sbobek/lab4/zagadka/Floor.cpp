#include "Floor.h"

Floor::Floor() :
      length(0), color(0) {
}

Floor::Floor(int length) :
      color(0) {
   this->length = length;
   for(int i = 1; i <= length; i++)
      content.push_back(Block());
}

Floor::~Floor() {
   content.clear();
}

Floor::Floor(const Floor &other) {
   for(list<Block>::const_iterator iter = other.content.begin(); iter != other.content.end(); ++iter)
      content.push_back(*iter);
   color = other.color;
   length = other.length;
}

int Floor::get(int n) {
   int i = 0;
   for(list<Block>::iterator iter = content.begin(); iter != content.end() && i < n; ++iter, i++)
      if(i == n - 1)
         return iter->getn();
}

void Floor::set(int n, int number) {
   int i = 0;
   for(list<Block>::iterator iter = content.begin(); iter != content.end() && i < n; ++iter, i++)
      if(i == n - 1)
         iter->setn(number);
}

void Floor::setcolor(int color) {
   this->color = color;
}

void Floor::show() {
   for(list<Block>::iterator iter = content.begin(); iter != content.end(); ++iter)
      iter->show();
}

int Floor::getcolor() {
   return this->color;
}

bool Floor::check() {
   bool ok = true;
   if(color == 1) {
      for(int i = 1; i <= length; i++)
         for(int j = 1; j <= length; j++)
            if(j != i && get(i) == get(j) && get(i) != 0)
               ok = false;
   } else if(color == 2) {
      ok = false;
      for(int i = 1; i <= length; i++)
         for(int j = 1; j <= length; j++)
            if(j != i && get(j) == get(i) && get(i) != 0)
               ok = true;
      if(!ok)
         for(int i = 1; i <= length; i++)
            if(get(i) == 0)
               ok = true;
   }
   return ok;
}

