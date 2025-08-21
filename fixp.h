#ifndef FIXP_H_
#define FIXP_H_

#include <stdio.h>
#include "incs/stdtypes.h"

typedef i32 fixed_t;

#define FXPBITS 16
#define FXPUNIT ((fixed_t)1<<FXPBITS)

f64 fixed2float(fixed_t input);
fixed_t float2fixed(f64 input);
fixed_t fixed_mul(fixed_t a1, fixed_t a2);
fixed_t fixed_div(fixed_t a1, fixed_t a2);
fixed_t fixed_sqrt(fixed_t n);

#endif /* FIXP_H_ */

#ifdef FIXP_IMPLEMENTATION

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
	return ((i64)a1*(i64)a2)>>FXPBITS;
}

fixed_t fixed_div(fixed_t a1, fixed_t a2)
{
	//printf("\nDEBUG: %lld\n", (a1<<FXPBITS)/a2 );
	return ((i64)a1<<FXPBITS)/(i64)a2;
}

/*
fixed_t fixed_sqrt(fixed_t n)
{
	if (n < 0) {
		return -1;
	}

	fixed_t left = 0, right = n, ans = 0;

	while (left <= right) {
		fixed_t mid = left + ((right - left)>>1);
		if ((i64)mid * mid <= (i64)n) {
			ans = mid;
			left = mid + 1;
		} else {
			right = mid - 1;
		}
	}

	return ans<<(FXPBITS>>1);
}
*/

#endif /* FIXP_IMPLEMENTATION */