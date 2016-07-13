#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

int a[10001][1001];
bool check[10001][1001];
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0,1,-1 };
int step = 0;

queue<pair<int, int> > q;

int N, M;

void bfs() {
	vector<int> x;
	vector<int> y;
	int nx, ny;
	while (!q.empty()) {
		while(!q.empty()){
			x.push_back(q.front().first);
			y.push_back(q.front().second);
			q.pop();
		}
		for (int i = 0; i < y.size(); i++) {
			for (int j = 0; j < 4; j++) {
				nx = x[i] + dx[j];
				ny = y[i] + dy[j];
				if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
					if (a[nx][ny] == 0&& check[nx][ny]==false) {
						a[nx][ny] = 1;
						q.push(make_pair(nx, ny));
						check[nx][ny] = true;
					}
				}
			}
		}
		x.clear();
		y.clear();
		step++;
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &a[i][j]);
			if (a[i][j] == 1) {
				q.push(make_pair(i, j));
				check[i][j] = true;
			}
		}
	}
	if (!q.empty()) 
		bfs();

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] == 0)
				step = 0;
		}
	}

	printf("%d\n", step-1);

	return 0;
}