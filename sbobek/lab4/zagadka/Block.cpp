#include "Block.h"

using namespace std;

Block::Block() :
      number(0) {
}

Block::Block(int number) {
   this->number = number;
}

Block::Block(const Block &other) {
   this->number = other.number;
}

Block::~Block() {
}

void Block::show() {
   cout << number << " ";
}

void Block::setn(int number) {
   this->number = number;
}

int Block::getn() {
   return this->number;
}

Block Block::get() {
   return *this;
}
