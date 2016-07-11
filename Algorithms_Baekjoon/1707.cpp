#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

vector<int> a[20001];
int check[20001];
bool ans = true;

void dfs(int node, int tmp) {
	if (check[node] == 0) {
		if (tmp % 2 == 0)
			check[node] = 1;
		else
			check[node] = 2;
		for (int i = 0; i < a[node].size(); i++) {
			dfs(a[node][i], tmp+1);
		}
	}
}

int main() {
	int test_case;
	scanf("%d", &test_case);

	for (int t = 0; t < test_case; t++) {
		memset(check, 0, sizeof(check));
		for (int i = 0; i < 20001; i++) {
			a[i].clear();
		}
		ans = true;
		int V, E;
		scanf("%d %d", &V, &E);
		for (int i = 0; i < E; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			a[u].push_back(v);
			a[v].push_back(u);
		}

		for (int i = 1; i <= V; i++) {
			dfs(i, 0);
		}
		
		for (int i = 1; i <= V; i++) {
			int tmp = check[i];
			for (int j = 0; j < a[i].size(); j++) {
				if (check[a[i][j]] == tmp)
					ans = false;
			}
		}

		printf("%s\n", ans ? "YES" : "NO");
	}

	return 0;
}