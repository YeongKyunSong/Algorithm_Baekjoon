#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>
#include <string>

#define INF 1000000000

using namespace std;

struct str {
	int node;
	int weight;
	str(int node, int weight) :node(node), weight(weight) {}
};

vector<str> a[20001];
long long int dist[20001];
bool check[20001];

int main() {
	int V, E, first;
	cin >> V >> E >> first;

	register int i;
	for (i = 0; i < E; i++) {
		int tmp1, tmp2, w;
		scanf("%d %d %d", &tmp1, &tmp2, &w);
		a[tmp1].push_back(str(tmp2, w));
	}
	priority_queue<pair<int, int> > pq;
	pq.push(make_pair(0, first));

	for (i = 0; i < 20001; i++) {
		dist[i] = INF;
	}
 	dist[first] = 0;

	while (!pq.empty()) {
		int node = pq.top().second;
		int weight = pq.top().first;
		pq.pop();

		if (check[node] == true)
			continue;
		check[node] = true;

		for (i = 0; i < a[node].size(); i++) {
			str next = a[node][i];
			if (dist[next.node] > dist[node] + next.weight) {
				dist[next.node] = dist[node] + next.weight;
				pq.push(make_pair(-dist[next.node], next.node));
			}
		}
	}

	for (i = 1; i <= V; i++) {
		if (dist[i] >= INF)
			printf("INF\n");
		else
			printf("%d\n", dist[i]);
	}


	return 0;
}