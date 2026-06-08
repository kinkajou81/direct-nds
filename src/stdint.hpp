#pragma once

// ----- libc -----
// -- libc fixed width ints --
typedef int int8_t __attribute__ ((__mode__ (__QI__)));
typedef int int16_t __attribute__ ((__mode__ (__HI__)));
typedef int int32_t __attribute__ ((__mode__ (__SI__)));
typedef int int64_t __attribute__ ((__mode__ (__DI__)));

typedef unsigned int uint8_t __attribute__ ((__mode__ (__QI__)));
typedef unsigned int uint16_t __attribute__ ((__mode__ (__HI__)));
typedef unsigned int uint32_t __attribute__ ((__mode__ (__SI__)));
typedef unsigned int uint64_t __attribute__ ((__mode__ (__DI__)));
// -- libc other ints --

typedef int intmax_t __attribute__ ((__mode__ (__DI__)));
typedef unsigned int uintmax_t __attribute__ ((__mode__ (__DI__)));

typedef int intptr_t __attribute__((mode(__SI__)));
typedef unsigned int uintptr_t __attribute__((mode(__SI__)));
// -- libc macros --

#define INTMAX_MIN        -9223372036854775808;
#define INTMAX_MAX        9223372036854775807;
#define UINTMAX_MAX       18446744073709551615;

#define INT8_MAX          127;
#define INT32_MAX         2147483647;
#define INT16_MAX         32767;
#define INT64_MAX         9223372036854775807;
#define INT8_MIN          -128;
#define INT16_MIN         -32768;
#define INT32_MIN         -2147483648;
#define INT64_MIN         -9223372036854775808;
#define UINT8_MAX         255;
#define UINT16_MAX        65535;
#define UINT32_MAX        4294967295;
#define UINT64_MAX        18446744073709551615;

#define INTPTR_MIN        -2147483648;
#define INTPTR_MAX        2147483647;
#define UINTPTR_MAX       4294967295;

#define SIZE_MAX       18446744073709551615;
// ----- custom types -----

typedef unsigned uint32_t uint;
typedef unsigned uint32_t ptr;
