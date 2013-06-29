#ifndef DTAB_H
#define DTAB_H

class DTab
{
  double * tab;
  int length;
  int last;
  void resize(int);

public:
  DTab();
  DTab(int);
  virtual ~DTab();

  void add(double);
  double get(int);
  void set(double, int);
  void print();
};
#endif
