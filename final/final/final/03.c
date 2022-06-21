#include <stdio.h>

int vertex[5][5] = {
	{1e9,   3, 1e9,   5, 1e9},
	{1e9, 1e9,   6,   2, 1e9},
	{1e9, 1e9, 1e9, 1e9,   2},
	{1e9,   1,   4, 1e9,   6},
	{  3, 1e9,   7, 1e9, 1e9}
};

int dis[5];
int vis[5];
char name[5];

int choose() {
	int i, min, minpos;
	min = 1e9;
	minpos = -1;

	for (i = 0; i < 5; i++) {

		if (dis[i] < min && vis[i] == -1) {
			min = dis[i];
			minpos = i;
		}
	}
	return minpos;
}

void shortest_path(int start) {
	for (int i = 0; i < 5; i++) {
		dis[i] = vertex[start][i];
		vis[i] = -1;
	}

	vis[start] = 0;
	dis[start] = 0;
	for (int i = 0; i < 4; i++) {
		int u = choose();

		vis[u] = i;
		for (int w = 0; w < 5; w++) {

			if (vis[w] == -1) {
				if (dis[u] + vertex[u][w] < dis[w]) {
					dis[w] = dis[u] + vertex[u][w];
				}
			}
		}
	}
}

int main() {
    name[0] = 's';
    name[1] = 't';
    name[2] = 'x';
    name[3] = 'y';
    name[4] = 'z';
    
	shortest_path(0);

	printf("Node : y, Cost : %d\ny", dis[3]);
	
	int print = 3;
	while (print != 0) {
		print = vis[print];
		printf(" <- %c", name[print]);
	}


	printf("\nNode : z, Cost : %d\nz", dis[4]);

	print = 4;
	while (print != 0) {
		print = vis[print];
		printf(" <- %c", name[print]);
	}
	
	return 0;
}
