#include <stdio.h>
#include <float.h>
#include <limits.h>
#include <ctype.h>
#include "GetArbitratyLines.h"
#include "Test.h"
#include "HW2.h"
#include "KnR_ch3.h"

int main() {
	test_iotap();
	system("pause");
	return 1;
}

unsigned short int rotBits(unsigned short int byte) {
	return (byte << 12 | byte >> 4);
}

unsigned short int swapBits(unsigned short int byte) {
	return (byte << 8) | ( byte >> 8);
}

int lastFourBitsOn(unsigned int byte) {
	int r = byte & 0xF;
	if (r == 0xD || r== 0xB ||r== 0xE || r == 0xF || r == 0x7)
		return 1;
	return -1;
}

int funcTester(int (*func)(char[])) {
	char c;
	char s[100];
	int i = 0;
	while ((c = getchar()) != EOF) {
		s[i] = c;
		i++;
	}
	func(s);
	//printf("hex to int: %11d\n", htoi(s));
}

int funcArrayCharTester(int (*func)(char[], char), char ch) {
	char c;
	char s[100];
	int i = 0;
	while ((c = getchar()) != EOF) {
		s[i] = c;
		i++;
	}
	func(s, ch);
	printf("%s", s);
}

int anyTest() {
	char some[] = "some";
	char match[] = "nein";
	int i = any(some, match);
	printf("%i\n", i);

	char somemore[] = "asdf";
	char none[] = "zxcv";
	int j = any(somemore, none);
	printf("%i\n", j);
}

int any(char s1[], char s2[]) {
	int i, j;
	char c;
	for (i = j = 0; s2[i] != '\0'; i++)
	{
		c = s2[i];
		for (j = 0; s1[j] != '\0'; j++)
			if (s1[j] == c)
			{
				return j;
			}		
	}
	return -1;
}

int squeeze2Test() {	
	char s[] = "ace of spades";
	char rmv[] = "aesdf";
	squeeze2(s, rmv);
	
	printf("%s", s);
}

void func2ArrayTester(int (*func)(char[], char[]), char ch[]) {
	char c;
	char s[100];
	int i = 0;
	while ((c = getchar()) != EOF) {
		s[i] = c;
		i++;
	}
	func(s, ch);
	printf("%s", s);
}

int squeeze2(char s1[], char s2[])
{
	int i, j, k;
	char c;
	for (i = j = k = 0; s2[i] != '\0'; i++)
	{
		c = s2[i];
		for (j = k = 0; s1[j] != '\0'; j++)
			if (s1[j] != c)
			{
				s1[k] = s1[j];
				k++;
			}				
		s1[k] = '\0';
	}
}

/* squeeze:  delete all c from s */   
int squeeze(char s[], int c) 
{ int i, j;
	for (i = j = 0; s[i] != '\0'; i++)
		if (s[i] != c) 
		s[j++] = s[i];
	s[j] = '\0'; 
}

 htoiTest() {
	char c;
	char s[100];
	int i = 0;
	while ((c = getchar()) != EOF){
		s[i] = c;
		i++;
	}
	htoi(s);
	//printf("hex to int: %11d\n", htoi(s));
}

/* htoi: convert hex string to integer */
int htoi(char s[])
{
	int c, af;
	int i = 0, n;	

	if (s[0] == '0' && tolower(s[1]) == 'x') 
	{ i = 2; }

		n = 0;
		for (; s[i] >= '0' && s[i] <= '9' || tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f'; ++i) {
			c = s[i] - '0';
			if (tolower(s[i]) >= 'a' && tolower(s[i]) <= 'f') {
				c = (int)tolower(s[i]) - 87;
			}
			n = 16 * n + c;
		}
	//return n;
		printf("hex to int: %11d\n", n);
}

forLoopAnalog() {
	int i, lim, bCount;
	bCount = 0;
	lim = 1000;
	char c;
	char s[1000];
	//for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
	//	s[i] = c;
	for (i = 0; 3 == (bCount = ((i < lim - 1) + ((c = getchar()) != '\n') + (c != EOF))); ++i)
		s[i] = c;	
}

int ranges() {
	unsigned char c;
	unsigned short s;
	unsigned int i;
	unsigned long l;
	unsigned long long ll;


	putchar('\n');
	printf("VALUE RANGES FOR INTEGER TYPES\nUPPERCASE comes from <limits.h>\n"
		"lowercase is calculated.\n\n");


	/* char */
	c = ~0;
	c >>= 1;
	printf("signed char:   %4d,           %4d\n", -c - 1, c);
	printf("SCHAR_MIN:     %4d, SCHAR_MAX %4d\n", SCHAR_MIN, SCHAR_MAX);
	printf("unsigned char: %4u,           %4u\n", 0, c * 2 + 1);
	printf("UCHAR_MAX:                     %4u\n", UCHAR_MAX);
	putchar('\n');

	/* short */
	s = ~0;
	s >>= 1;
	printf("signed short:   %6d,           %6d\n", -s - 1, s);
	printf("SHRT_MIN:       %6d, SHRT_MAX: %6d\n", SHRT_MIN, SHRT_MAX);
	printf("unsigned short: %6u,           %6u\n", 0, s * 2 + 1);
	printf("USHRT_MAX:                        %6u\n", USHRT_MAX);
	putchar('\n');

	/* int */
	i = ~0;
	i >>= 1;
	printf("signed int:    %11d,          %11d\n", i * -1 - 1, i);
	printf("INT_MIN:       %11d, INT_MAX: %11d\n", INT_MIN, INT_MAX);
	printf("unsigned int:  %11u,          %11u\n", 0, i * 2 + 1);
	printf("UINT_MAX:                            %11u\n", UINT_MAX);
	putchar('\n');

	/* long */
	l = ~0;
	l >>= 1;
	printf("signed long:   %11ld,           %11ld\n", l * -1 - 1, l);
	printf("LONG_MIN:      %11ld, LONG_MAX: %11ld\n", LONG_MIN, LONG_MAX);
	printf("unsigned long: %11lu,           %11lu\n", 0l, l * 2 + 1);
	printf("ULONG_MAX:                            %11lu\n", ULONG_MAX);
	putchar('\n');

	/* long long */
	ll = ~0;
	ll >>= 1;
	printf("signed long long:   %20lld,            %20lld\n", ll * -1 - 1, ll);
	printf("LLONG_MIN:          %20lld, LLONG_MAX: %20lld\n", LLONG_MIN, LLONG_MAX);
	printf("unsigned long long: %20llu,            %20llu\n", 0ll, ll * 2 + 1);
	printf("ULLONG_MAX:                                          %20llu\n", ULLONG_MAX);
	putchar('\n');

	printf("float min:	%g\n", FLT_MIN);
	printf("float max:	%g\n", FLT_MAX);
	printf("double min:		%g\n", DBL_MIN);
	printf("double max:		%g\n", DBL_MAX);
	printf("long double min:	%g\n", LDBL_MIN);
	printf("long double max:	%g\n", LDBL_MAX);
	putchar('\n');

	float fl = 0;
	float decimal = 0.0;
	float change = 0.1;
	float prev = 0.0;
	while (change != 0) {		
		for (int i = 0; i < 9; i++) {
			decimal = decimal + change;
			decimal = decimal + 1;
		}
		printf("float max:     %g\n", decimal);
		prev = change;
		change = change * 0.1;
	}
	printf("%.100f", prev);
	return 0;
}

wc() {
#define IN 1;
#define OUT 0;

	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
		}
		else if (state == 0) {
			state = IN;
			++nw;
		}
	}
	printf("%d %d %d\n", nl, nw, nc);
}

ws() {
#define IN 1;
#define OUT 0;

	int c, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			if (state != 0)
				putchar('\n');
			state = OUT;
		}
		else {
			putchar(c);
			state = IN;
		}
	}	
}

//1-13
wordHisto() {
	int wordsSlots[1000], currentLength, i, c, j;
	currentLength = 0;

	for (i = 0; i < 1000; i++) {
		wordsSlots[i] = 0;
	}

	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			++wordsSlots[currentLength];
			currentLength = 0;
		}
		else {
			++currentLength;
		}
	}

	for (i = 0; i < 1000; i++) {
		if (wordsSlots[i] != 0) {
			printf("\n%i", i);
			for (j = 0; j < wordsSlots[i]; j++) {
				putchar('-');
			}
		}
	}
}
