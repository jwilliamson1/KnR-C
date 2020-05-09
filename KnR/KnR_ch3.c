#include <stdio.h>

void writeexpansion(char start, char end, char* t, int pos);
void expand(char s[], char t[], int len);

void expandtest() {
	char t1[] = "a-";
	char t2[] = "-a";
	char t3[] = "a-b";
	char t4[] = "a-c";
	char t5[] = "-a-c-";
	char ts[5][20] = { "a-", "-a", "a-b", "a-c", "-a-c-" };
	int lens = *(&ts + 1) - ts;
	char r[100];
	for (int i = 0; i < lens; i++) {
		expand(ts[i], r, 20);
		printf("%s\n", r);
	}
	//char r1[100], r2[100], r3[100], r4[100], r5[100];
	//int len = *(&t1 + 1) - t1;
	//expand(t1, r1, len);
}

void expand(char s[], char t[], int len) {
	int pos = 0;
	int dashSeen = 0;
	char start;
	char end;
	enum states {LITERAL, INLOWER, INUPPER, NUMERIC};
	enum states state;
	state = LITERAL;
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == '-' && state != LITERAL) {
			if (dashSeen) {
				t[pos - 1] = '-';
				t[pos++] = s[i];
			}
			dashSeen = 1;
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			switch (state) {
			case LITERAL: {
				start = s[i];
				state = INLOWER;
				t[pos++] = s[i];
				break;
			}
			case INLOWER: {
				if (dashSeen) {
					if (s[i] > start) {
						end = s[i];
						writeexpansion(start+1, end, t, & pos);
						state = LITERAL;
					}
				}
				else {
					start = s[i];
					t[pos++] = s[i];
				}
				break;
			}
			}
		}
		else if (s[i] >= 'A' && s[i] <= 'Z') {

		}
		else {
			t[pos++] = s[i];
		}
		i++;
	}
	switch (state) {
	case INLOWER: {
		if (dashSeen) {
			t[pos++] = '-';
		}
		break;
	}
	}
	t[pos] = '\0';
}

void writeexpansion(char start, char end, char * t, int * pos) {
	while (start <= end) {
		t[(*pos)++] = start++;		
	}
}

int binsearch(int x, int v[], int n) {
	int low, high, mid, count;
	count = 1;
	low = 0;
	high = n - 1;
	while (v[(mid = (low + high) / 2)] != x && v[mid+1] != x && low + 1 < high) {
		printf("iterations: %i\n", count++);
		if (x < v[mid])
			high = mid-1;
		else
			low = mid;
	}
	if (v[mid] == x)
		return mid;

	if (v[mid+1] == x)
		return mid+1;
	return -1;
}

void binsearchtest() {
	int domain[] = { 1 };
	int domain2[] = { 1, 2 };
	int domain3[] = { 1, 2, 3, 4 };
	int pos;


	//pos = binsearch(0, domain, 1);
	//printf("pos: %i\n", pos);

	//pos = binsearch(1, domain, 1);
	//printf("pos: %i\n", pos);

	//pos = binsearch(1, domain2, 2);
	//printf("pos: %i\n", pos);

	//pos = binsearch(2, domain2, 2);
	//printf("pos: %i\n", pos);
	for (int i = 0; i < 4; i++) {
		pos = binsearch(i + 1, domain3, 4);
		printf("pos: %i\n", pos);
	}
}

void escape(char s[], char t[]) {
	int len = *(&s + 1) - s;
	int tPos = 0;
	for (int i = 0; i < len; i++) {
		switch (s[i]) {
		case '\\':
			t[tPos++] = '\\';
			t[tPos++] = '\\';
			break;
		case '\n':
			t[tPos++] = '\\';
			t[tPos++] = 'n';
			break;
		case '\t':
			t[tPos++] = '\\';
			t[tPos++] = 't';
			break;
		default:
			t[tPos++] = s[i];
		}
	}
}

void unescape(char s[], char t[]) {
	int len = *(&s + 1) - s;
	int tPos = 0;
	for (int i = 0; i < len; i++) {		
		if (s[i] == '\\') {
			i++;
			switch (s[i]) {
				case '\\':
					t[tPos++] = '\\';
				case 'n':
					t[tPos++] = '\n';					
					break;
				case 't':
					t[tPos++] = '\t';					
					break;
				default:
					break;
				}
			}
		else
			t[tPos++] = s[i];
	}
}


void escapetest() {
	char s[] = "asdf\tas\\f\nasdf\tasdf";
	char t[100];
	char u[100];

	escape(s, t);

	for (int i = 0; i < 22; i++) {
		printf("%c", t[i]);
	}
	printf("\n");

	unescape(t, u);

	for (int i = 0; i < 19; i++) {
		printf("%c", u[i]);
	}
	printf("\n");
}