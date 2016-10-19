#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

vector<int> n[1001];
int check[1001];
queue<int> q;

int N, M, V;

void dfs(int v) {
	printf("%d ", v);
	check[v] = true;
	for (int i = 0; i < n[v].size(); i++) {
		if (check[n[v][i]] == false) {
			dfs(n[v][i]);
		}
	}
}
void bfs(int v) {
	q.push(v);
	check[v] = true;
	while (!q.empty()) {
		int tmp = q.front();
		printf("%d ", tmp);
		q.pop();
		for (int i = 0; i < n[tmp].size(); i++) {
			if (check[n[tmp][i]] == false) {
				q.push(n[tmp][i]);
				check[n[tmp][i]] = true;
			}
		}
	}
}

int main() {
	scanf("%d %d %d", &N, &M, &V);

	for (int i = 0; i < M; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		n[a].push_back(b);
		n[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		sort(n[i].begin(), n[i].end());
	}

	dfs(V);

	memset(check, false, sizeof(check));
	printf("\n");

	bfs(V);

	return 0;
}