# Introduction to Embedded Systems Software and Development Environments

- [Coursera](https://www.coursera.org/learn/introduction-embedded-systems/home/welcome)
- [Github](https://github.com/afosdick/ese-coursera-course1)

# Copyright (C) 2017 by Alex Fosdick - University of Colorado

## My Notes
- compile using gcc -o stats.out stats.c
- run using ./stats.out
- compile and run using gcc -o stats.out stats.c && ./stats.out

## Compiler Fun

### Arm Compiler

Create (usless for now) executable. Useless as we are on the wrong target system.
```
arm-none-eabi-gcc main.c -o main.out --specs=nosys.specs -std=c99 -mcpu=cortex-m0plus -mthumb -Werror
```

Create assmbler file:
```
arm-none-eabi-gcc -std=c99 -mcpu=cortex-m0plus -mthumb -Wall -S main.c -o main.s
```

Create assmbler file + debug symbols:
```
arm-none-eabi-gcc -std=c99 -mcpu=cortex-m0plus -mthumb -Wall -S main.c -o main_debug.s -g
```

### GCC compiler
```
gcc -std=c99 -o main.out main.c
```

### Providing defines at compile time
```
gcc -std=c99 -o main.out main.c -DMSP_PLATFORM -DSERIAL_PORT=\"HELLO\"  && ./main.out
```
This generates two defines, i.e. MSP_PLATFORM (==true) and SERIAL_PORT (=="HELLO")


### Preprocessor

#### Macro Functions using #define

- #ifdef
- #ifndef
- #elif
- #else
- #endif

#define <MACRO-FUNCTION>(<Params>) ({OPERATION})

```c
#define SQUARE(x) (x*x)
```

Using #define and #undef as a feature


```c
#define SUPER_FAST_CPU

#ifdef SUPER_FAST_CPU
    // run code only if super fast CPU
#endif

#ifndef SUPER_FAST_CPU
    // run code only on slow CPU
#endif
```

Macro directives can also be chained I guess...
```c
#if defined ( KL25_PLATFROM ) && !defined ( MSP_PLATFORM)
  kl25_init();
#elif defined ( MSP_PLATFORM ) &&  !defined( KL25_PLATFROM )
  msp_init();
#else 
  #error "Plaese specify one platfrom target"
#endif  
```

####  #include - Standing on the shoulder of giants:

#### Being #pragma - tic
