#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

int v[100001];
int c[100001];
int s[100001];
int n;

int dfs(int vertex, int check, int step){
	if (s[vertex]>0) {
		if (step != s[vertex])
			return 0;
		else {
			return check - c[vertex];
		}
	}
	else {
		c[vertex] = check;
		s[vertex] = step;
		dfs(v[vertex], check + 1, step);
	}
}

int main() {
	int test_case;
	scanf("%d", &test_case);

	for (int t = 0; t < test_case; t++) {
		memset(v, 0, sizeof(v));
		memset(c, 0, sizeof(c));
		memset(s, 0, sizeof(s));
		int ans = 0;
		scanf("%d", &n);

		for (int i = 1; i <= n; i++) {
			scanf("%d", &v[i]);
		}

		for (int i = 1; i <= n; i++) {
			if (c[i] == 0) {
				ans+=dfs(i, 1, i);
			}
		}
		printf("%d\n", n - ans);
	}
	return 0;
}