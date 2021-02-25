/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.h
 * @brief  Get statstics I guess...
 *
 * Calculates means and maxes and other stuffses
 *
 * @author Johannes Rebling
 * @date 02/2021
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Add Your Declarations and Function Comments here */

/**
 * @brief Print array statistics
 *
 * A function that prints the statistics of an array including minimum,
 * maximum, mean, and median.
 *
 * @param array_ pointer to char array containing the data 
 * @param nElements number of elements in the array
 *
 * @return void
 */
void print_statistics(unsigned char* array_, unsigned int nElements);

/**
 * @brief Print array content
 *
 * Given an array of data and a length, prints the array to the screen
 *
 * @param array_ pointer to char array containing the data 
 * @param nElements number of elements in the array
 *
 * @return void
 */
void print_array(unsigned char* array_, unsigned int nElements);

/**
 * @brief Retrun median array value
 *
 * Given an array of data and a length, returns the median value
 *
 * @param array_ pointer to char array containing the data 
 * @param nElements number of elements in the array
 *
 * @return median value (float)
 */
float find_median(unsigned char *array_, unsigned int nElements);

/**
 * @brief Retrun mean array value
 *
 * Given an array of data and a length, returns the mean value
 *
 * @param array_ pointer to char array containing the data 
 * @param nElements number of elements in the array
 *
 * @return mean value (float)
 */
float find_mean(unsigned char *array_, unsigned int nElements);

/**
 * @brief Retrun max array value
 *
 * Given an array of data and a length, returns the max value
 *
 * @param array_ pointer to char array containing the data 
 * @param nElements number of elements in the array
 *
 * @return max value
 */
unsigned char find_maximum(unsigned char *array_, unsigned int nElements);

/**
 * @brief Retrun min array value
 *
 * Given an array of data and a length, returns the min value
 *
 * @param array_ pointer to char array containing the data 
 * @param nElements number of elements in the array
 *
 * @return min value
 */
unsigned char find_minimum(unsigned char *array_, unsigned int nElements);

/**
 * @brief Retrun min array value
 *
 * Given an array of data and a length, sorts the array from largest to smallest. 
 * (The zeroth Element should be the largest value, and the last element (n-1) 
 * should be the smallest value. )
 *
 * @param array_ pointer to char array containing the data 
 * @param nElements number of elements in the array
 *
 * @return min value
 */
void sort_array(unsigned char* array_, unsigned int nElements);


#endif /* __STATS_H__ */
