#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

int a[10001][101];
int c[10001][101];
int s = 1;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };

int N, M;

queue<pair<int,int>> q;

void bfs(int x, int y, int step) {
	c[x][y] = step;
	
	while (!q.empty()) {
		int f = q.front().first;
		int t = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = f + dx[i];
			int ny = t + dy[i];

			if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
				if (a[nx][ny] > 0 ) {
					if (c[f][t]+1 < c[nx][ny] || c[nx][ny]==0) {
						c[nx][ny] = c[f][t]+1;
						q.push(make_pair(nx, ny));
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int tmp;
			scanf("%1d", &tmp);
			a[i][j] = tmp;
		}
	}
	q.push(make_pair(0, 0));

	bfs(0, 0, 1);

	printf("%d\n", c[N - 1][M - 1]);

	return 0;
}