#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define count 11

int m[count][count];
int s[count][count];
int matrix[8][count][count];
static int *result;
int n[8];

static int* calc(static int* a, static int* b, int s, int mid, int e) {
	int *ret = (int *)malloc(sizeof(int) * count * count);
	for (int i = 1; i <= n[s]; i++) {
		for (int j = 1; j <= n[e]; j++) {
			*(ret + i * count + j) = 0;
			for (int k = 1; k <= n[mid]; k++) {
				*(ret + i * count + j) += *(a + i * count + k) * *(b + k * count + j);
			}
		}
	}

	return ret;
}

static int* recursive(int start, int end) {
	if (start == end) {
		printf(" %d ", start);
		return *(matrix + start);
	}
	printf("(");
	int* a, * b, * ret;
	a = recursive(start, s[start][end]);
	b = recursive(s[start][end] + 1, end);

	ret = calc(a, b, start - 1, s[start][end], end);
	printf(")");

	return ret;
}

int main() {
	int size = 3;
	srand(time(NULL));

	printf("Input a sequence of dimensions of the matrices ( <?,?,?,?> ) : ");
	scanf("<%d,%d,%d,%d>", &n[0], &n[1], &n[2], &n[3]);

	for (int k = 1; k <= size; k++) {
		for (int i = 1; i <= n[k - 1]; i++) {
			for (int j = 1; j <= n[k]; j++) {
				matrix[k][i][j] = rand() % 10;
			}
		}
	}


	for (int k = 2; k <= size; k++) {
		for (int i = 1; i <= size - k + 1; i++) {
			int j = i + k - 1;
			m[i][j] = 1e9;

			for (int k = i; k < j; k++) {
				int min = m[i][k] + m[k + 1][j] + n[i - 1] * n[k] * n[j];
				if (min < m[i][j]) {
					m[i][j] = min;
					s[i][j] = k;
				}
			}
		}
	}

	printf("Minimum number of computations : %d\n", m[1][size]);
	printf("Optimal chain order : ");
	result = recursive(1, size);
	printf("\n");
	printf("Output Matrix\n");
	for (int i = 1; i <= n[0]; i++) {
		for (int j = 1; j <= n[size]; j++) {
			printf("%d\t", *(result + i * count + j));
		}
		printf("\n");
	}

	return 0;
}
