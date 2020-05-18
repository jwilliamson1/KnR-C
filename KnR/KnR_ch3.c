#include <stdio.h>
#include <time.h>

void writeexpansion(char start, char end, char* t, int pos);
void expand(char s[], char t[], int len);

void expandtest() {
	char ts[11][20] = { "!a-c", "a-1-8-c-e", "a-bc-d", "z-a", "a--b", "a-", "-a", "a-b", "a-c", "-a-z-", "-a-"};
	int lens = *(&ts + 1) - ts;
	char r[100];
	for (int i = 0; i < lens; i++) {
		expand(ts[i], r, 20);
		printf("%s\n", r);
	}
}

enum states { LITERAL, INLOWER, INUPPER, NUMERIC };

enum states determineexpandtype(char s[]) {

}

void expand(char s[], char t[], int len) {
	int pos = 0;
	int dashSeen = 0;
	char start;
	char end;
	
	enum states state;
	state = LITERAL;
	int i = 0;
	while (s[i] != '\0') {
		if (s[i] == '-' && state != LITERAL) {
			if (!dashSeen) {
				dashSeen = 1;
				// don't bump cuz we might overwrite
				t[pos++] = '-';
			}
			else {
				t[pos++] = '-';
			}			
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			switch (state) {
			case INUPPER:
			case NUMERIC:
			case LITERAL: {
				start = s[i];
				state = INLOWER;
				t[pos++] = s[i];
				dashSeen = 0;
				break;
			}
			case INLOWER: {
				if (dashSeen) {
					if (s[i] > start) {
						end = s[i];
						writeexpansion(start+1, end, t, & pos);
						state = LITERAL;
						dashSeen = 0;
					}
					else {
						state = LITERAL;
						t[pos++] = '-';
						t[pos++] = s[i];
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
			switch (state) {
			case INLOWER:
			case NUMERIC:
			case LITERAL: {
				start = s[i];
				state = INUPPER;
				t[pos++] = s[i];
				dashSeen = 0;
				break;
			}
			case INUPPER: {
				if (dashSeen) {
					if (s[i] > start) {
						end = s[i];
						writeexpansion(start + 1, end, t, &pos);
						state = LITERAL;
						dashSeen = 0;
					}
					else {
						state = LITERAL;
						t[pos++] = '-';
						t[pos++] = s[i];
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
		else if (s[i] >= '0' && s[i] <= '9') {
			switch (state) {
			case INLOWER:
			case INUPPER:
			case LITERAL: {
				start = s[i];
				state = NUMERIC;
				t[pos++] = s[i];
				dashSeen = 0;
				break;				
			}
			case NUMERIC: {
				if (dashSeen) {
					if (s[i] > start) {
						end = s[i];
						writeexpansion(start + 1, end, t, &pos);
						state = LITERAL;
						dashSeen = 0;
					}
					else {
						state = LITERAL;
						t[pos++] = '-';
						t[pos++] = s[i];
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
		else {
			t[pos++] = s[i];
		}
		i++;
	}
	switch (state) {

	if (dashSeen) {
		t[pos++] = '-';
	}
	break;
	
	}
	t[pos] = '\0';
}

void writeexpansion(char start, char end, char * t, int * pos) {
	(*pos)--;
	while (start <= end) {
		t[(*pos)++] = start++;
	}
}

int iterations = 0;

int binsearch2(int x, int v[], int n) {
	int low, mid, high;

	low = 0;
	high = n - 1;
	while (low < high) {
		iterations++;
		mid = (low + high) / 2;
		if (x <= v[mid])
			high = mid;
		else
			low = mid + 1;
	}

	if (x == v[low])
		return low;
	else
		return -1;
}

int binsearch1(int x, int v[], int n) {
	int low, mid, high;
	low = 0;
	high = n - 1;
	while (low <= high) {
		mid = (low + high) / 2;
		iterations++;
		if (x < v[mid])
			high = mid - 1;
		else if (x > v[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

void binsearchtest() {
	clock_t time_taken;
	int pos;
	// mid point 65535
	long domain4[131070];

	for (int i = 0; i < 131070; i++)
		domain4[i] = i;

	time_taken = clock();

	for (int i = 0; i < 131070; i++) {
		pos = binsearch1(i, domain4, 131070);
	}

	time_taken = clock() - time_taken;

	printf("binsearch1() took %lu clocks (%lu seconds)\n",
		(unsigned long)time_taken,
		(unsigned long)time_taken / CLOCKS_PER_SEC);

	printf("iterations: %i\n", iterations);

	iterations = 0;

	time_taken = clock();

	for (int i = 0; i < 131070; i++) {
		pos = binsearch2(i, domain4, 131070);
	}

	time_taken = clock() - time_taken;

	printf("binsearch2() took %lu clocks (%lu seconds)\n",
		(unsigned long)time_taken,
		(unsigned long)time_taken / CLOCKS_PER_SEC);

	printf("iterations: %i\n", iterations);

	for (int i = 0; i < 10; i++) {
		pos = binsearch1(i, domain4, 10);
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