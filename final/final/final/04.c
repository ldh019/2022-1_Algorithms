#include <stdio.h>

typedef struct vertex {
	int d;
	int pre;
}vertex;
/*
int main() {
	int flag = 1;
	vertex node[5];

	int edge[5][5] = {
		{1e9,   5, 1e9,   6, 1e9},
		{1e9, 1e9,   5,   8,  -4},
		{1e9,  -2, 1e9, 1e9, 1e9},
		{1e9, 1e9,  -3, 1e9,   9},
		{  2, 1e9,   4, 1e9, 1e9}
	};

	for (int i = 0; i < 5; i++) {
		node[i].d = 1e9;
		node[i].pre = -1;
	}

	node[0].d = 0;

	for (int v = 1; v < 5; v++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (edge[i][j] != 1e9) {
					if (node[i].d != 1e9 && node[i].d + edge[i][j] < node[j].d) {
						node[j].d = node[i].d + edge[i][j];
						node[j].pre = i;
					}
				}
			}
		}

		for (int i = 0; i < 5; i++) {
			if (node[i].d == 1e9 && node[i].pre == -1)
				printf("Node : %d, Distance : INF, Predecessor : NIL\n", i);
			else if (node[i].d == 1e9)
				printf("Node : %d, Distance : INF, Predecessor : %3d\n", i, node[i].pre);
			else if (node[i].pre == -1)
				printf("Node : %d, Distance : %3d, Predecessor : NIL\n", i, node[i].d);
			else
				printf("Node : %d, Distance : %3d, Predecessor : %3d\n", i, node[i].d, node[i].pre);
		}
		printf("\n\n");
	}

	for (int i = 0; i < 5 && flag; i++) {
		for (int j = 0; j < 5 && flag; j++) {
			if (edge[i][j] != 1e9) {
				if (node[i].d != 1e9 && node[i].d + edge[i][j] < node[j].d) {
					flag = 0;
				}
			}
		}
	}

	if (!flag) {
		printf("Negative-Weight Cycle exists");
	}
	else
		printf("Available to use Bellman-Ford Algorithm");

	return 0;
}*/