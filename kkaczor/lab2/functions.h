/**
 * @file functions.h
 * @author Marcin Lachowicz
 * @date 07-05-2013
 * @brief operations on char* collections
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

/**
 * @brief function sums two collections and allocates memory for result
 * @param c1 - collection
 * @param c2 - collection
 * @return sum of collections
 */
char* getSumOfCollections(const char* c1, const char* c2);

/**
 * function intersects two collections and allocates memory for result
 * @param c1 - collection
 * @param c2 - collection
 * @return  intersection of collections
 */
char* getIntersectionOfCollections(const char* c1, const char* c2);

/**
 * @brief functions compare two collections
 * @param c1 - collection
 * @param c2 - collection
 * @return true if collections are the same
 */
bool compareCollections(const char* c1, const char* c2);

#endif /* FUNCTIONS_H_ */
