#ifndef MARSJANIN_H
#define MARSJANIN_H


class Marsjanin
{
public:
  static int licznik;
  Marsjanin();
  Marsjanin(const Marsjanin &);
  ~Marsjanin();

  void atakuj();
  void ukryj();
};

#endif
