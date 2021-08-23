long long sum(int *a, int n) {
	long long ans = 0;
    int i;

    for(i = 0; i < n; i++)
        ans = ans + a[i];
	return ans;
}
