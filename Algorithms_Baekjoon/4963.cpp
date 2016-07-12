#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

int a[51][51];
int c[51][51];
//int d[51][51];
int dx[] = { 1,-1,0,0 ,1,-1,1,-1};
int dy[] = { 0,0,-1,1 ,-1,1,1,-1};

int w, h;

void dfs(int x, int y, int s) {
	c[x][y] = s;
	for (int i = 0; i < 8; i++) {
		int nx = x+dx[i];
		int ny = y+dy[i];

		if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
			if (c[nx][ny] == 0 && a[nx][ny]>0) {
				dfs(nx, ny, s);
			}
		}
	}
}

int main() {
	while (1) {
		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0) {
			break;
		}
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		int s = 1;

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				scanf("%d", &a[i][j]);
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (a[i][j] > 0 && c[i][j] == 0) {
					dfs(i, j, s);
					s++;
				}
			}
		}
		printf("%d\n", s-1);
	}

	return 0;
}