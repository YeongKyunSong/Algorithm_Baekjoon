#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>
#include <string>
#include <map>
#include <list>

using namespace std;

int vertex[32001];
vector<int> a[32001];
bool check[32001];

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	register int i;
	for (i = 0; i < M; i++) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		vertex[tmp2]++;
		a[tmp1].push_back(tmp2);
	}
	queue<int> q;
	for (i = 1; i <= N; i++) {
		if (vertex[i] == 0)
			q.push(i);
	}
	vector<int> ans;

	while (!q.empty()) {
		int now = q.front();
		ans.push_back(now);
		q.pop();
		for (i = 0; i < a[now].size(); i++) {
			vertex[a[now][i]]--;
			if (vertex[a[now][i]] == 0)
				q.push(a[now][i]);
		}
	}

	for (i = 0; i < N; i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}