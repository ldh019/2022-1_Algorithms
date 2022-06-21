#include <stdio.h>

typedef enum color {
	WHITE, GRAY, BLACK
}color;

typedef struct vertex {
    char name;
	color color;
	int d;
	int pre;
}vertex;

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
	
	node[0].name = 'r';
	node[1].name = 's';
	node[2].name = 't';
	node[3].name = 'u';ㄴ
	node[4].name = 'v';
	node[5].name = 'w';
	node[6].name = 'x';
	node[7].name = 'y';

	int s = 1;

	int queue[20];
	int f, r;ㄴ
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
	    if (node[i].pre == -1)
	        printf(" %c    %d   NIL\n", node[i].name, node[i].d);
		else
		    printf(" %c    %d    %c\n", node[i].name, node[i].d, node[node[i].pre].name);
	}

	return 0;
}
