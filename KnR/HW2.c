#include <stdio.h>
#include <limits.h>
unsigned short int copybits(unsigned short int x, int p, int n, unsigned short int y) {
	//gets right most n bits from y 10001110
	unsigned short int yMask1 = (~(~0 << n)) << p;
	unsigned short int xMask = ~(yMask1);
	unsigned short int xwithoutn = xMask & x;
	unsigned short int ywithoutOthers = yMask1 & y;
	unsigned short int res = ywithoutOthers | xwithoutn;
	
	return res;
}

unsigned short int setbits(unsigned short int x, int p, int n, unsigned short int y) {
	unsigned short int yMask = ~((~0) << n);
	unsigned short int ywithoutothers = yMask & y;
	unsigned short int yshifted = yMask << p;
	unsigned short int xbiteraser = yMask << p;
	unsigned short int res = (xbiteraser & x) | yshifted;
	return res;
}

unsigned short int rotbits(unsigned short int x, int n) {
	/* calculate number of bits in type */
	size_t s = sizeof(x) * CHAR_BIT;
	size_t p;

	/* limit shift to range 0 - (s - 1) */
	if (n < s)
		p = n;
	else
		p = n % s;

	/* if either is zero then the original value is unchanged */
	if ((0 == x) || (0 == p))
		return x;

	return (x >> p) | (x << (s - p));
}