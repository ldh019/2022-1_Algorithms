#include <stdio.h>

typedef enum color {
	WHITE, GRAY, BLACK
}color;

typedef struct vertex {
	color color;
	int d;
	int pre;
}vertex;
/*
int main() {
	int linked_mat[8][8] = {
		{0, 1, 0, 0, 1, 0, 0, 0},
		{1, 0, 0, 0, 0, 1, 0, 0},
		{0, 0, 0, 1, 0, 1, 1, 0},
		{0, 0, 1, 0, 0, 0, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0},
		{0, 1, 1, 0, 0, 0, 1, 0},
		{0, 0, 1, 1, 0, 1, 0, 1},
		{0, 0, 0, 1, 0, 0, 1, 0}
	};

	vertex node[8];

	for (int i = 0; i < 8; i++) {
		node[i].color = WHITE;
		node[i].d = 1e9;
		node[i].pre = -1;
	}

	int s = 1;

	int queue[20];
	int f, r;
	f = r = 0;

	node[s].color = GRAY;
	node[s].d = 0;

	queue[r++] = s;

	while (f < r) {
		int front = queue[f++];

		for (int i = 0; i < 8; i++) {
			if (linked_mat[front][i] == 1) {
				if (node[i].color == WHITE) {
					node[i].color = GRAY;
					node[i].d = node[front].d + 1;
					node[i].pre = front;
					queue[r++] = i;
				}
			}
		}

		node[front].color = BLACK;
	}

	printf("Num  Dis  Pre\n");

	for (int i = 0; i < 8; i++) {
		printf(" %d    %d    %d\n", i, node[i].d, node[i].pre);
	}

	return 0;
}*/