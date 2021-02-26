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

#include <stdio.h>

// #define KL25_PLATFROM
// #define MSP_PLATFORM

// #pragma GCC poison printf

#ifndef SERIAL_PORT
#define SERIAL_PORT "NOT_PROVIDED"
#endif

const char *port = SERIAL_PORT;

#if defined(KL25_PLATFROM) && !defined(MSP_PLATFORM)
  // kl25_init();
#elif defined(MSP_PLATFORM) && !defined(KL25_PLATFROM)
  // msp_init();
#else
  #error "Plaese specify one platfrom target"
#endif

#define SQUARE(x) (x * x)

int main(void){

  printf("\nModule Demo File!\n");
  printf("I have the best of serial ports: %s\n", port);
  return 0;
}

