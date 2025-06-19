#include <stdio.h>
#include <math.h>
#include <inttypes.h>

#include "fixp.h"

// using those in fixp.h file can conflict with other libraries/applications
typedef int16_t i16;
typedef uint16_t u16;
typedef int32_t i32;
typedef uint32_t u32;
typedef int64_t i64;
typedef uint64_t u64;

typedef float f32;
typedef double f64;

f64 fixed2float(fixed_t input)
{
	return (f64)input / FXPUNIT;
}

fixed_t float2fixed(f64 input)
{
	return input * FXPUNIT;
}

fixed_t fixed_mul(fixed_t a1, fixed_t a2)
{
	return (a1*a2)>>FXPBITS;
}

fixed_t fixed_div(fixed_t a1, fixed_t a2)
{
	//printf("\nDEBUG: %lld\n", (a1<<FXPBITS)/a2 );
	return (a1<<FXPBITS)/a2;
}

fixed_t fixed_sqrt(fixed_t n)
{
	if (n < 0) {
		return -1;
	}

	fixed_t left = 0, right = n, ans = 0;

	while (left <= right) {
		fixed_t mid = left + ((right - left)>>1);
		if (mid * mid <= n) {
			ans = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return ans<<(FXPBITS>>1);
}