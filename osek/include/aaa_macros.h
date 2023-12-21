#ifndef _MACROS_H_
#define _MACROS_H_

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define ARRAY_SSIZE(x) (int)(sizeof(x) / sizeof((x)[0]))

#define SIZE_K(KB) (1024U * (KB))
#define SIZE_M(MB) SIZE_K(1024U * (MB))

/* Turn on one bit in a 32-bit word */
#define BIT(_x_) ((uint32_t)(1U) << (_x_))
#define BIT32(_x_) ((uint32_t)(1U) << (_x_))

/* Turn on one bit in a 64-bit word */
#define BIT64(_x_) ((uint64_t)(1U) << (_x_))

#define DIV_ROUND_UP(x, y) (((x) + (y) - 1U) / (y))

#define min(a, b) (((a) < (b)) ? (a) : (b))

#define max(a, b) (((a) > (b)) ? (a) : (b))

#ifndef U64_C
#define U64_C(x) UINT64_C(x)
#endif

#ifndef U32_C
#define U32_C(x) UINT32_C(x)
#endif

#ifndef U16_C
#define U16_C(x) UINT16_C(x)
#endif

#ifndef U8_C
#define U8_C(x) UINT8_C(x)
#endif

#endif
