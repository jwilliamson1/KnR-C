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

void escape(char s[], char t[]) {
	int len = *(&s + 1) - s;
	int tPos = 0;
	for (int i = 0; i < len; i++) {
		switch (s[i]) {
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

void escapetest() {
	char s[] = "asdf\nasdf\tasdf\n";
	char t[100];

	escape(s, t);

	for (int i = 0; i < 18; i++) {
		printf("%c", t[i]);
	}
	printf("\n");

}