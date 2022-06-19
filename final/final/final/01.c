#include <stdio.h>

#define max(a, b) a > b ? a : b

int memoized_cut_rod(int p[11], int n) {
	int r[11] = { 0, };

	for (int i = 0; i <= n; i++) {
		r[i] = -1e9;
	}

	return memoized_cut_rod_aux(p, n, r);
}

int memoized_cut_rod_aux(int p[11], int n, int r[11]) {
	int q;
	int idx = -1;

	if (r[n] >= 0)
		return r[n];
	if (n == 0)
		q = 0;
	else {
		q = -1e9;
		for (int i = 1; i <= n; i++) {
			int tmp = q;
			q = max(q, p[i] + memoized_cut_rod_aux(p, n - i, r));
			if (tmp != q) {
				idx = i;
			}
		}
		if (idx != -1) printf("Length %2d : %d + %d, Value : %2d\n", n, idx, n - idx, q);
	}
	r[n] = q;

	return q;
}

int main() {
	int len = 10;
	int p[11] = { 0, 1, 4, 5, 7, 9, 11, 13, 13, 15, 16 };

	int ret = memoized_cut_rod(p, len);
	printf("Maximum amount : %d", ret);

	return 0;
}

