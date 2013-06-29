/**
 *@file aghGenerator.h
 *@author Wojciech Kasperek
 *@date 09-05-2013
 *@brief The definition of abstract aghGenerator class
 */
#ifndef AGHGENERATOR_H_
#define AGHGENERATOR_H_

/**
 *@class aghGenerator
 *@author Wojciech Kasperek
 *@date 09-05-2013
 *@brief The definition of abstract aghGenerator class
 */
class aghGenerator {
   protected:

      int beginning; ///Beginning of range
      int end; ///End of range
      int r_variable; ///Generated random variable
      int seed; ///Generator's seed
      string generatorName; /// Generator's name

      /**
       * @brief Range beginning setter
       * @param _beg - range beginning
       * @return No value returns
       */
      void setBeginning(int);

      /**
       * @brief Range end setter
       * @param _end - range end
       * @return No value returns
       */
      void setEnd(int);

   public:

      /**
       * @brief The default constructor
       */
      aghGenerator(void);

      /**
       * @brief Constructor
       * @param _beg - range beginning
       * @param _end - range end
       * @param _seed - seed
       * @param _name - generator's name
       */
      aghGenerator(int, int, int, string);

      /**
       * @brief The default destructor
       */
      virtual ~aghGenerator(void);

      /**
       * @brief Variable getter
       * @return variable
       */
      int getVar(void) const;

      /**
       * @brief Range setter
       * @param _beg - beginning
       * @param _end - end
       * @return No value returns
       */
      void setRange(int, int);

      /**
       * @brief Calculates range
       * @return range
       */
      int getRange(void) const;

      /**
       * @brief Range beginning getter
       * @return beginning
       */
      int getBeginning(void) const;

      /**
       * @brief Range end getter
       * @return end
       */
      int getEnd(void) const;

      /**
       * @brief Seed setter
       * @param _seed - seed
       * @return No value returns
       */
      virtual void setSeed(int);

      /**
       * @brief Seed getter
       * @return Seed
       */
      int getSeed(void) const;

      /**
       * @brief generator's name setter
       * @param new generator's names
       * @return no value returns
       */
      void setGeneratorName(string);

      /**
       * @brief Generator getter
       * @return generator's name
       */
      string getGeneratorName(void) const;

      /**
       * @brief method prints generator's name
       * @param stream
       * @return no value returns
       */
      void printName(ostream & = cout) const;

      /**
       * @brief Function that generates random number
       */
      virtual void generate(void) = 0;

      /**
       * @brief Function that prints generated variable to output stream
       * @param  str - output stream, default: cout
       * @return No value returns
       */
      void print(ostream& = cout) const;
};

#endif /* AGHGENERATOR_H_ */
