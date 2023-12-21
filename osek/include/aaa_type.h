#ifndef _AAA_TYPE_H
#define _AAA_TYPE_H

#if(0)

char int8_t;
typedef int int32_t;

typedef unsigned long int uint64_t;
typedef unsigned int uint32_t;
typedef unsigned char uint8_t;

typedef unsigned int tegrabl_error_t;
typedef unsigned int bnum_t ;
typedef uint64_t off_t;
typedef uint64_t time_t;

typedef long BaseType_t;
typedef unsigned long UBaseType_t;
typedef unsigned char bool;

#define false 0
#define true  1

#ifndef NULL
#define NULL (void*)0
#endif

#else

#include <stdbool.h>
#include <stdint.h>
#include <FreeRTOS.h>

#endif



#endif