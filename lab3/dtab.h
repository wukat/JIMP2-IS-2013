#ifndef DTAB_H
#define DTAB_H

class DTab
{
private:
  double * tab;
  int length;
  int last;
  void resize(int newSize);

public:
  DTab();
  DTab(int initLength);
  ~DTab();

  void add(double element);
  double get(int index);
  void set(double element, int index);
  void print();
};
#endif
