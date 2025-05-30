#include <stdio.h>
#include <math.h>
#include "incs/stdtypes.h"

#define FXPBITS 16
#define FXPUNIT ((fixed_t)1<<FXPBITS)

typedef i128 fixed_t;

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


#define NUM_DECIMAL_PLACES 100

void calcDiv(i64 A, i64 B) {
	if (B == 0) {
		printf("Infinity\n");
		return;
	}

	long long result = A / B;
	long long remainder = A % B;
	long long decimal = remainder / B;

	printf("%lld.", result);

	for (int i = 0; i < NUM_DECIMAL_PLACES; i++) {
		remainder *= 10;
		decimal = remainder / B;
		remainder = remainder % B;

		printf("%lld", decimal);
	}

	printf("\n");
}


i32 main()
{
	//f64 a = 324.67;
	f64 a = 13342.54;
	f64 b = -9.67;
	
	fixed_t Fa = float2fixed(a);
	fixed_t Fb = float2fixed(b);
	
	
	printf("\n\nFXPBITS:%d\n", FXPBITS);
	
	printf("a=%f, fl2fi=%lld, fi2fl=%.10f\n", a, Fa, fixed2float(Fa));
	printf("b=%f, fl2fi=%lld, fi2fl=%.10f\n", b, Fb, fixed2float(Fb));

	puts("");
	
	// Multiplying
	printf("a=%f, b=%f\n"
		   "fl mul=%f\nfx mul=%.10f\n\n",
		   a, b, a*b , fixed2float( fixed_mul(Fa, Fb) )
	);

	// Dividing
	printf("a=%f, b=%f\n"
			   "fl div=%f\nfx div=%.10f\n\n",
			   a, b, a/b , fixed2float( fixed_div(Fa ,Fb) )
	);
	
	// sum
	printf("fl sum=%f\nfx sum=%.10f\n\n", a+b, fixed2float(Fa+Fb));
	
	//sqrt
	printf("fl sqrt=%f\nfx sqrt=%.10f\n", sqrt(a), fixed2float(fixed_sqrt(Fa)));
	
}

