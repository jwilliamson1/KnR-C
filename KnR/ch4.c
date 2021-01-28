#include "KnR_ch3.h"
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
