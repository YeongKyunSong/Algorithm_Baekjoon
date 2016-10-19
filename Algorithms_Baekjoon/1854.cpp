#define _CRT_SECURE_NO_WARNINGS
#define INF 2000000

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

struct info {
	int to;
	int cost;
	info(int to, int cost) : to(to), cost(cost) {}
};

vector<info> a[1001];
priority_queue<int> sum[1001];
priority_queue<info> q;
int n, m, k;

bool operator < (info a, info b) {
	return a.cost > b.cost;
}

int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		a[x].push_back(info(y, c));
	}

	sum[1].push(0);
	q.push(info(1, 0));

	while (!q.empty()) {
		info tmp = q.top();
		q.pop();
		int x = tmp.to;
		int cost = tmp.cost;

		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i].to;
			if (sum[y].size() < k || sum[y].top() > cost + a[x][i].cost) {
				if (sum[y].size() == k)
					sum[y].pop();
				sum[y].push(cost + a[x][i].cost);
				q.push(info(y, cost + a[x][i].cost));

			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (sum[i].size()!= k)
			cout << -1 << endl;
		else {
			cout << sum[i].top() << endl;
		}
	}

	return 0;
}