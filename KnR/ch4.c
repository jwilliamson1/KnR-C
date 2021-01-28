#include "KnR_ch3.h"
//4-2
/* atof: convert string s to double */
double atof(char s[])
{
	double val, power, epower;
	int i, sign, esign;
	for (i = 0; isspace(s[i]); i++) /* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++) {
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}
	if (s[i] == 'e' || s[i] == 'E')
		i++;
	esign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (epower = 0.0; isdigit(s[i]); i++) {
		epower = 10.0 * epower + (s[i] - '0');
		power = epower;
	}
		
	if (esign < 0)
		power = 1 / power;

	return sign * val / power;
}

void test_atof() {
	double sum, atof(char[]);
	char line[100];
	int getline(char line[], int max);
	sum = 0;
	while (getline(line, 100) > 0)
		printf("\t%g\n", sum += atof(line));
	return 0;
}

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
	int i, j, k;
	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;
}

int strindexR(char s[], char t[]) {
	reverse(s);
	reverse(t);
	int i = strindex(s, t);

	if (i >= 0)
		return strlen(s) - i;

	return i;
}

void test_strindex() {
	char s1[4] = { "aac" };
	char f1[2] = { "a" };
	int i = strindexR(s1, f1);
	printf("%i\n", i);
}
