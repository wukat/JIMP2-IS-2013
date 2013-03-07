#include "dziecko.h"
#include "rodzic.h"
#include <iostream>

int main()
{
  Dziecko Grodzka("Anna", "Grodzka", 55, "Wojnowo");
  Rodzic tatus("Ryszard", "Kalisz", 65, Grodzka);

  tatus.PrzepiszDoInnejSzkoly("Sejm");
}
