#ifndef BLOCZEK_H
#define BLOCZEK_H

using namespace std;

enum kolor_b
{
  UNDEF = -1;
  ZOLTY = 0,
  NIEBIESKI = 1,
  ROZOWY = 2;
};

class Bloczek
{
private:
  kolor_b kolor;
  int cyfra;

public:
  Bloczek();
  Bloczek(kolor_b, int);
  Bloczek(const Bloczek &);
  ~Bloczek();
};

#endif
