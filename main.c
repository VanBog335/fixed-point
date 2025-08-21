#include <stdio.h>
#include <math.h>

#define FIXP_IMPLEMENTATION
#include "fixp.h"

#define NUM_DECIMAL_PLACES 100

void calcDiv(int64_t A, int64_t B) {
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


int32_t main()
{
	double a = 1342.54;
	double b = -9.67;
	
	fixed_t Fa = float2fixed(a);
	fixed_t Fb = float2fixed(b);
	
	
	printf("\n\nFXPBITS:%d\n", FXPBITS);
	
	printf("a=%f, fl2fi=%d, fi2fl=%.10f\n", a, Fa, fixed2float(Fa));
	printf("b=%f, fl2fi=%d, fi2fl=%.10f\n", b, Fb, fixed2float(Fb));

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
	//printf("fl sqrt=%f\nfx sqrt=%.10f\n", sqrt(a), fixed2float(fixed_sqrt(Fa)));
	
}