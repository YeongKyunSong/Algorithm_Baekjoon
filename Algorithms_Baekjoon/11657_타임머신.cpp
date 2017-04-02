#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>
#include <string>

using namespace std;

#define INF 2147483647

struct edge {
	int from;
	int to;
	int cost;
};
int dist[501];

int main() {
	int t;
	int n, m;
	scanf("%d %d", &n, &m);
	vector<edge> a(m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a[i].from, &a[i].to, &a[i].cost);
	}
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[1] = 0;
	bool cycle = false;
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < m; j++) {
			int x = a[j].from;
			int y = a[j].to;
			int z = a[j].cost;
			if (dist[x] != INF && dist[y] > dist[x] + z) {
				dist[y] = dist[x] + z;
				if (i == n)
					cycle = true;
			}
		}
	}

	if (cycle == true) {
		printf("-1\n");
	}
	else {
		for (int i = 2; i <= n; i++) {
			if (dist[i] >= INF)
				printf("-1\n");
			else {
				printf("%d\n", dist[i]);
			}
		}
	}
	return 0;
}