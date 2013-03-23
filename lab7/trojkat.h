#ifndef TROJKAT_H
#define TROJKAT_H

class Ksztalt;

class Trojkat: public Ksztalt
{
  public:
    Trojkat() : Ksztalt() {};
    virtual void rysuj() const;
    virtual ~Trojkat() {};
};

#endif
