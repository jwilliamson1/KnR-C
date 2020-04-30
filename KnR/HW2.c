#include <stdio.h>
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
	unsigned short int rightNMask = ~((~0) << n);
	unsigned short int rightNOnly = rightNMask & x;
	unsigned short int toShiftLeft = x - rightNOnly;
	unsigned short int leftShifted = x << toShiftLeft;
	unsigned short int rightShifted = x >> n;
	unsigned short res = leftShifted & rightShifted;
	return res;
}

int bitcount(unsigned x)
{
	int b;
	for (b = 0; x != 0; x >>= 1) {
		x &= (x - 1);
		b++;
	}
	return b;
}