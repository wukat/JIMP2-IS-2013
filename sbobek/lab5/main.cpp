#include "punkt.h"
#include "complex.h"
#include "matrix.h"

using namespace std;

int main()
{
  Punkt a(1,1);
  
  cin >> a;
  cout << a;

  Complex b(5,6);
  Complex c(7,1);
  Complex result(1,2);
  
  result = b + c;
  result.show();
  result = b - c;
  result.show();
  result = b * c;
  result.show();
  result = b / c;
  result.show();
  b+=c;
  b.show();
  b-=c;
  b.show();
  c.show();
  if (b!=c) cout << "a"; else cout << "b";


  Matrix fajna = (Matrix) b;

  

  return 0;
}
