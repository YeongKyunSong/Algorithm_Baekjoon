#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

vector<int> a;
vector<bool> check;

int cnt = 0;

void dfs(int node) {
	if (check[node] == false) {
		check[node] = true;
		dfs(a[node] - 1);
	}
}

void connected(int N) {
	for (int i = 0; i < N; i++) {
		if (check[i] == false) {
			dfs(i);
			cnt++;
		}
	}
}

int main() {
	int test_case;
	scanf("%d", &test_case);

	for (int t = 0; t < test_case; t++) {
		a.clear();
		check.clear();
		cnt = 0;
		int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			int tmp;
			scanf("%d", &tmp);
			a.push_back(tmp);
		}
		check.assign(N, false);
		
		connected(N);

		printf("%d\n", cnt);
	}
	return 0;
}