#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

vector<int> a[1001];
bool check[1001];
int N, M;
int cnt = 0;
void dfs(int node) {
	check[node] = true;

	for (int i = 0; i < a[node].size(); i++) {
		if (check[a[node][i]] == false) {
			dfs(a[node][i]);
		}
	}

}

void connected() {
	for (int i = 1; i < N + 1; i++) {
		if (check[i] == false) {
			dfs(i);
			cnt++;
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		a[u].push_back(v);
		a[v].push_back(u);
	}

	connected();

	printf("%d", cnt);

	return 0;
}