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