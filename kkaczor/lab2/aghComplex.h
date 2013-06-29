/**
 * @file aghComplex.h
 * @author Marcin Lachowicz
 * @date 10-05-2013
 * @brief Header file for aghComplex class
 */

#ifndef AGHCOMPLEX_H_
#define AGHCOMPLEX_H_

/**
 * @class aghComplex
 * @author Marcin Lachowicz
 * @date 10-05-2013
 * @brief class represents complex number
 */
class aghComplex {
   public:
      /**
       * @brief default constructor
       */
      aghComplex();

      /**
       * @brief parametric constructor
       * @param re - real part
       * @param im - imaginary part
       */
      aghComplex(double re, double im);

      /**
       * @brief default destructor
       */
      virtual ~aghComplex();

      /**
       * @brief overloaded + operator
       * @param component - complex number
       * @return sum of two complex numbers
       */
      const aghComplex operator+(const aghComplex& component);

      /**
       * @brief overloaded * operator
       * @param component - complex number
       * @return multiplication of two complex numbers
       */
      const aghComplex operator*(const aghComplex& component);

      /**
       * @brief overloaded  += operator
       * @param component - complex number
       */
      void operator+=(const aghComplex& component);

      /**
       * @brief overloaded ==  operator
       * @param  pattern - complex number
       * @return true if numbers are equal
       */
      bool operator==(const aghComplex& pattern);

      /**
       * @brief overloaded !=  operator
       * @param  pattern - complex number
       * @return true if numbers are not equal
       */
      bool operator!=(const aghComplex& pattern);

   private:
      double re, im;
};

#endif /* AGHCOMPLEX_H_ */
