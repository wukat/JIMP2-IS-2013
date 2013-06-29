#include "aghInclude.h"

int main(void) {
   ofstream resultFile;
   resultFile.open("resultFile.txt", ios::trunc);

   vector<aghGenerator*> generators;

   generators.push_back(new aghFibGen(0, 999, 127, 97));
   generators.push_back(new aghMTGen(0, 999));
   generators.push_back(new aghLFGen(0, 999));
   generators.push_back(new aghLehmer(0, 999, 75, 65537)); // ZX Spectrum config
   generators.push_back(new aghStdGen(0, 999));

   for(vector<aghGenerator*>::iterator iter = generators.begin(); iter != generators.end(); iter++) {
      (*iter)->printName();
      (*iter)->printName(resultFile);

      for(int i = 0; i < 10; i++) {
         (*iter)->generate();
         (*iter)->print();
         (*iter)->print(resultFile);
      }
      cout << endl;
      resultFile << endl;

      vector<aghGenTest*> tests;
      tests.push_back(new aghChiSqr(*iter, 5, 100000));
      tests.push_back(new aghPITest(*iter, 5, 100000));
      tests.push_back(new aghAverageTest(*iter, 5, 100000));

      for(vector<aghGenTest*>::iterator jter = tests.begin(); jter != tests.end(); jter++) {
         (*jter)->test();
         (*jter)->print();
         (*jter)->print(resultFile);
         delete (*jter);
      }
      tests.clear();
      delete (*iter);
   }
   generators.clear();

   resultFile.close();

   return 0;
}
