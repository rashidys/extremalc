#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef __APPLE__

#include <stdint.h>

typedef uint16_t char16_t;
typedef uint16_t char32_t;

#else 
#include <uchar.h>
#endif
