#ifndef COMMON_TYPES_H
#define COMMON_TYPES_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

// Integer type aliases
typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t i8;
typedef int16_t i16;
typedef int32_t i32;
typedef int64_t i64;

// Floating point type aliases
typedef float f32;
typedef double f64;

// Pointer-sized integer
typedef uintptr_t uptr;

// Optional macro for compile-time assertions
#define STATIC_ASSERT(condition, message) \
    typedef char static_assertion__##message[(condition) ? 1 : -1]

// Optional: Compile-time type size checks
STATIC_ASSERT(sizeof(u8) == 1, u8_must_be_1_byte);
STATIC_ASSERT(sizeof(u32) == 4, u32_must_be_4_bytes);

#ifdef __cplusplus
}
#endif

#endif  // COMMON_TYPES_H
