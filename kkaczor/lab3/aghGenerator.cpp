#include "aghInclude.h"

aghGenerator::aghGenerator(void) {

}

aghGenerator::aghGenerator(int _beg, int _end, int _seed, string _name) { //_beg < _end, _seed >= 0
   setRange(_beg, _end);
   setSeed(_seed);
   setGeneratorName(_name);
}

aghGenerator::~aghGenerator(void) {
}

int aghGenerator::getVar(void) const {
   return r_variable;
}

void aghGenerator::setRange(int _beg, int _end) {
   if(_end <= _beg) {
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   } else {
      setEnd(_end);
      setBeginning(_beg);
   }
   return;
}

int aghGenerator::getRange(void) const {
   return end - beginning + 1;
}

void aghGenerator::setBeginning(int _beg) {
   beginning = _beg;
   return;
}

int aghGenerator::getBeginning(void) const {
   return beginning;
}

void aghGenerator::setEnd(int _end) {
   end = _end;
   return;
}

int aghGenerator::getEnd(void) const {
   return end;
}

void aghGenerator::setSeed(int _seed) {
   if(_seed < 0) {
      throw aghException(0, "Wrong values given", __FILE__, __LINE__);
   } else {
      seed = _seed;
   }
   return;
}

string aghGenerator::getGeneratorName(void) const {
   return generatorName;
}

void aghGenerator::setGeneratorName(string name) {
   generatorName = name;
   return;
}

void aghGenerator::printName(ostream & stream) const {
   stream << generatorName << endl;
   return;
}

int aghGenerator::getSeed(void) const {
   return seed;
}

void aghGenerator::print(ostream& str) const {
   str << getVar() << endl;
   return;
}

