#ifndef FIXP_H
#define FIXP_H

#include <inttypes.h>

typedef _BitInt(128) fixed_t;

#define FXPBITS 16
#define FXPUNIT ((fixed_t)1<<FXPBITS)

double fixed2float(fixed_t input);
fixed_t float2fixed(double input);
fixed_t fixed_mul(fixed_t a1, fixed_t a2);
fixed_t fixed_div(fixed_t a1, fixed_t a2);
fixed_t fixed_sqrt(fixed_t n);

#endif