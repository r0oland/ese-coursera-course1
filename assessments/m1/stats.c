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
 * @file stats.c
 * @brief Get statstics I guess...
 *
 * Calculates means and maxes and other stuffses
 *
 * @author Johannes Rebling
 * @date 02/2021
 *
 */



#include <stdio.h>
#include <stdint.h> // fixed width integer types
#include "stats.h"

/* Size of the Data Set */
// const int16_t N_ELEMENTS = (40);


void main() {
  uint8_t testArray[] = {34, 201, 190, 154, 8, 194, 2, 6,
                        114, 88, 45, 76, 123, 87, 25, 23,
                        200, 122, 150, 90, 92, 87, 177, 244,
                        201, 6, 12, 60, 8, 2, 5, 67,
                        7, 87, 250, 230, 99, 3, 100, 90};

  size_t N_ELEMENTS = sizeof(testArray) / sizeof(testArray[0]);

  /* Other Variable Declarations Go Here */
  /* Statistics and Printing Functions Go Here */

  printf("Getting rolling on that embedded C-train...chooo cooo\n");

  printf("Lets first look at our beautiful array:\n");
  print_array(testArray, N_ELEMENTS);
  print_statistics(testArray, N_ELEMENTS);
  printf("Lets sort that array and see how things have changed...:\n");
  sort_array(testArray, N_ELEMENTS);
  print_array(testArray, N_ELEMENTS);
  print_statistics(testArray, N_ELEMENTS);
}

/* Add other Implementation File Code Here */
//------------------------------------------------------------------------------
void print_statistics(uint8_t *array_, uint8_t nElements)
{
  printf("Array statistics:\n");
  printf("Median: %2.2f \n", find_median(array_, nElements));
  printf("  Mean: %2.2f \n", find_mean(array_, nElements));
  printf("   Max: %i \n", find_maximum(array_, nElements));
  printf("   Min: %i \n", find_minimum(array_, nElements));
}

//------------------------------------------------------------------------------
void print_array(uint8_t* array_, uint8_t nElements){
  const uint8_t nNumbersPerLine = 10;
  for (uint8_t idx = 1; idx <= nElements; idx++)
  {
    printf("%03i", array_[idx-1]);
    if (idx % nNumbersPerLine == 0){
      printf("\n");
    }
    else{
      printf(", ");
    }
  }
  printf("\n");
  return;
}

//------------------------------------------------------------------------------
float find_median(uint8_t *array_, uint8_t nElements)
{
  return 0.0;
}

//------------------------------------------------------------------------------
float find_mean(uint8_t *array_, uint8_t nElements)
{
  uint16_t tempSum = 0;
  //TODO check that nElements * max uint8_t will always fit in uint16_t
  for (uint8_t idx = 0; idx < nElements; idx++)
  {
    tempSum += array_[idx];
  }
  float mean = tempSum / (float)nElements;
  return mean;
}

//------------------------------------------------------------------------------
uint8_t find_maximum(uint8_t *array_, uint8_t nElements)
{
  uint8_t max = array_[0]; // start with first element, so we don't start with 0
  for (uint8_t idx=0; idx < nElements; idx++){
    if (array_[idx] > max){
      max = array_[idx];
    }
  }
  return max;
}

//------------------------------------------------------------------------------
uint8_t find_minimum(uint8_t *array_, uint8_t nElements)
{
  uint8_t min = array_[0]; // start with first element, so we don't start with 0
  for (uint8_t idx = 0; idx < nElements; idx++)
  {
    if (array_[idx] < min)
    {
      min = array_[idx];
    }
  }
  return min;
}

//------------------------------------------------------------------------------
void sort_array(uint8_t *array_, uint8_t nElements)
{
  uint8_t sortArray[nElements]; // is this always init to 0?
  for (uint8_t i = 0; i < nElements; i++)
  {
    sortArray[i] = 0;
  }

  uint8_t sortIdx = 0;
  for (uint8_t i = 0; i < nElements; i++)
  {
    sortIdx = 0;
    uint8_t sortValue = array_[i];
    while (sortValue >= sortArray[sortIdx])
    {
      sortIdx++;
      if (sortIdx >= nElements){
        break;
      }
    }
    sortIdx--; // this is now the element we need to overwrite with a new value

    uint8_t sortBefore = sortArray[sortIdx];
    uint8_t sortAfter = sortArray[sortIdx+1];
    // move all array elements back one to insert new one
    for (uint8_t j = 0; j < sortIdx+1; j++)
    {
      sortArray[j-1] = sortArray[j];
    }
    // sortArray[sortIdx + 1] = sortArray[sortIdx];
    sortArray[sortIdx] = sortValue;
    // printf("sortVal: %3i | sortIdx: %3i | before: %3i | after: %3i\n",
    //        sortValue, sortIdx, sortBefore, sortAfter);
    // print_array(sortArray, nElements);
  }

  // now we should have a sorted array, lets copy it to our orig array
  for (uint8_t i = 0; i < nElements; i++)
  {
    array_[i] = sortArray[i];
  }

  return;
}
