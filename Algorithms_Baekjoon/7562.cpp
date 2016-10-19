#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

int sx, sy;
int ex, ey;
int n;

struct info {
	int x;
	int y;
	int cnt;
	info(int x, int y, int cnt) : x(x), y(y), cnt(cnt) {}
};

queue<info> q;

bool check[301][301];

int go() {
	while (!q.empty()) {
		info tmp(0, 0, 0);
		tmp = q.front();
		q.pop();

		if (tmp.x == ex && tmp.y == ey)
			return tmp.cnt;

		if (tmp.x + 1 < n&& tmp.y + 2 < n && check[tmp.x+1][tmp.y+2]==0) {
			check[tmp.x + 1][tmp.y + 2] = 1;
			info temp(tmp.x + 1, tmp.y + 2, tmp.cnt + 1);
			q.push(temp);
		}
		if (tmp.x + 1 < n && tmp.y - 2 >= 0 && check[tmp.x + 1][tmp.y - 2] == 0) {
			check[tmp.x + 1][tmp.y - 2] = 1;
			info temp(tmp.x + 1, tmp.y - 2, tmp.cnt + 1);
			q.push(temp);
		}
		if (tmp.x + 2 < n && tmp.y + 1 < n&& check[tmp.x + 2][tmp.y + 1] == 0) {
			check[tmp.x + 2][tmp.y + 1] = 1;
			info temp(tmp.x + 2, tmp.y + 1, tmp.cnt + 1);
			q.push(temp);
		}
		if (tmp.x + 2 < n && tmp.y - 1 >= 0 && check[tmp.x + 2][tmp.y - 1] == 0) {
			check[tmp.x + 2][tmp.y - 1] = 1;
			info temp(tmp.x + 2, tmp.y - 1, tmp.cnt + 1);
			q.push(temp);
		}
		if (tmp.x - 1 >= 0 && tmp.y + 2 <n && check[tmp.x - 1][tmp.y + 2] == 0) {
			check[tmp.x - 1][tmp.y + 2] = 1;
			info temp(tmp.x - 1, tmp.y + 2, tmp.cnt + 1);
			q.push(temp);
		}
		if (tmp.x - 1 >= 0 && tmp.y - 2 >= 0 && check[tmp.x - 1][tmp.y -2] == 0) {
			check[tmp.x - 1][tmp.y - 2] = 1;
			info temp(tmp.x - 1, tmp.y - 2, tmp.cnt + 1);
			q.push(temp);
		}
		if (tmp.x - 2 >= 0 && tmp.y + 1 < n&& check[tmp.x -2][tmp.y + 1] == 0) {
			check[tmp.x - 2][tmp.y + 1] = 1;
			info temp(tmp.x - 2, tmp.y + 1, tmp.cnt + 1);
			q.push(temp);
		}
		if (tmp.x - 2 >= 0 && tmp.y - 1 >= 0 && check[tmp.x -2][tmp.y -1] == 0) {
			check[tmp.x - 2][tmp.y - 1] = 1;
			info temp(tmp.x - 2, tmp.y - 1, tmp.cnt + 1);
			q.push(temp);
		}
	}
}

int main() {
	int test;
	cin >> test;
	while (test--) {
		memset(check, 0, sizeof(check));
		while (!q.empty())
			q.pop();
		cin >> n;
		cin >> sx >> sy;
		cin >> ex >> ey;

		info tmp(sx, sy,0);
		q.push(tmp);

		cout << go() << endl;
	}
}