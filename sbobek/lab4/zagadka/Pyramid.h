#ifndef PYRAMID_H
#define PYRAMID_H
#include "Block.h"
#include "Floor.h"

using namespace std;

class Pyramid {
   private:
      int height;
      list<Floor> floors;

   public:
      Pyramid();
      Pyramid(int);
      Pyramid(const Pyramid &);
      ~Pyramid();

      Floor getf(int);
      int get(int, int);
      void color_set(int, int);
      void set(int, int, int);
      bool is_done();
      bool check_floor(int);
      bool check_block(int, int);
      bool check_oth(int, int);
      void fill(int, int, bool &, int, int);
      bool try_to_complete();
      bool solve_pyramid();
      void show();
};

#endif
