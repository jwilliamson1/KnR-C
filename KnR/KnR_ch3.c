int binsearch(int x, int v[], int n) {
	int low, high, mid, count;
	count = 1;
	low = 0;
	high = n - 1;
	while (v[(mid = (low + high) / 2)] != x && low+1 < high) {
		printf("%i\n", count++);
		if (x < v[mid])
			high = mid-1;
		else
			low = mid;
	}
	if (v[mid] == x)
		return mid;
	return -1;
}