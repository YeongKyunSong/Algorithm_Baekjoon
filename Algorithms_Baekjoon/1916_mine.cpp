#include<iostream>
#include<stdio.h>
#include<queue>
#include<vector>

using namespace std;

#define INF 2000000000;
struct info {
	int to;
	int cost;
	info(int to, int cost) : to(to), cost(cost) {}
};
int n, m;
int start, tail;
vector<info> a[1001];
int check[1001];
bool chk[1001];
struct cmp {
	bool operator () (const pair<int, int> &a, const pair<int, int> &b) {
		return a.second > b.second;
	}
};
int main() {
	cin >> n >> m;
	for (int i = 0; i <= n; i++) {
		check[i] = INF;
	}
	for (int i = 0; i < m; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		a[x].push_back(info(y, c));
	}
	cin >> start >> tail;

	priority_queue<pair<int,int>,vector<pair<int,int>>,cmp> pq;
	for (int i = 0; i < a[start].size(); i++) {
		pq.push(make_pair(a[start][i].to, a[start][i].cost));
		check[a[start][i].to] = a[start][i].cost;
	}

	while (!pq.empty()) {
		pair<int, int> tmp;
		tmp = pq.top();
		int x = tmp.first;
		int c = tmp.second;
		pq.pop();
		if (chk[x] == true)
			continue;

		chk[x] = true;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i].to;
			if (check[y] > a[x][i].cost + c) {
				check[y] = a[x][i].cost + c;
				pq.push(make_pair(y, check[y]));
			}
		}
	}

	cout << check[tail] << endl;

	return 0;
}