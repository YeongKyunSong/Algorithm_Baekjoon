#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <string>
#include <map>
#include <queue>

using namespace std;

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };


int main() {
	map<int, int> dist;
	int start = 0;
	for (int i = 0; i < 9; i++) {
		int tmp;
		scanf("%d", &tmp);
		if (tmp == 0) {
			tmp = 9;
		}
		start = start * 10 + tmp;
	}
	dist[start] = 0;
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int tmp = q.front();
		q.pop();
		string s = to_string(tmp);
		int z = s.find('9');
		int x = z / 3;
		int y = z % 3;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < 3 && ny >= 0 && ny < 3) {
				string now = s;
				swap(now[x*3+y], now[nx * 3 + ny]);
				int next = stoi(now);
				if (dist.count(next) == 0) {
					dist[next] = dist[tmp] + 1;
					q.push(next);
				}
			}
		}
	}
	if (dist.count(123456789) == 0) {
		cout << -1 << endl;
	}
	else
		cout << dist[123456789] << endl;

	return 0;
}