#ifndef BLOCK_H
#define BLOCK_H
#include <iostream>

class Block {
   private:
      int number;

   public:
      Block();
      Block(int);
      Block(const Block &);
      ~Block();

      void show();
      void setn(int);
      int getn();
      Block get();
};

#endif
