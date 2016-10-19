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

int home[51][51];
//int check[51][51];
int sx, sy;
int ex, ey;
int fd = 1;
int n;
int m = 2500;

struct info {
	int x;
	int y;
	int dir;
	int cnt;
	int chk[50][50];
	info(int x, int y, int cnt, int dir) : x(x), y(y), cnt(cnt), dir(dir) {
		for (int i = 0; i < 51; i++) {
			for (int j = 0; j < 51; j++) {
				chk[i][j] = 0;
			}
		}
	}
};

queue<info> q;

void left(int x, int y, int cnt, int dir) {
	//home[x][y] = 3;
	if (dir == 1) {
		dir = 4;
		y--;
	}
	else if (dir == 2) {
		dir = 3;
		y++;
	}
	else if (dir == 3) {
		dir = 2;
		x--;
	}
	else if (dir == 4) {
		dir = 1;
		x++;
	}
	info tmp(x, y, cnt + 1, dir);
	tmp.chk[x][y] = 3;
	q.push(tmp);
}
void right(int x, int y, int cnt, int dir) {
	//home[x][y] = 4;
	if (dir == 1) {
		dir = 3;
		y++;
	}
	else if (dir == 2) {
		dir = 4;
		y--;
	}
	else if (dir == 3) {
		dir = 1;
		x++;
	}
	else if (dir == 4) {
		dir = 2;
		x--;
	}
	info tmp(x, y, cnt + 1, dir);
	tmp.chk[x][y] = 4;
	q.push(tmp);
}
void empty(int x, int y, int cnt, int dir) {
	//home[x][y] = 0;
	if (dir == 1) {
		x++;
	}
	else if (dir == 2) {
		x--;
	}
	else if (dir == 3) {
		y++;
	}
	else if (dir == 4) {
		y--;
	}
	info tmp(x, y, cnt, dir);
	q.push(tmp);
}

void bfs(int x, int y, int d) {
	info tmp(x, y, 0, d);
	q.push(tmp);
	while (!q.empty()) {
		info tmp = q.front();
		q.pop();
		int a = tmp.x;
		int b = tmp.y;
		int c = tmp.cnt;
		int d = tmp.dir;
		if (c>m)
			continue;
		if (a == ex&&b == ey) {
			if (m > c)
				m = c;
		}
		/*if (check[a][b] > 2)
			continue;*/
		else if (home[a][b] == 2)
			continue;
		else if (home[a][b] == 1) {
			//check[a][b]++;
			left(a, b, c, d);
			right(a, b, c, d);
			empty(a, b, c, d);
		}
		else if (tmp.chk[a][b] == 3) {
			//check[a][b]++;
			left(a, b, c, d);
		}
		else if (tmp.chk[a][b] == 4) {
			//check[a][b]++;
			right(a, b, c, d);
		}
		else if (home[a][b] == 0 || home[a][b] == 5) {
			//check[a][b]++;
			empty(a, b, c, d);
		}
	}
}

int main() {
	string a;
	int flag = 0;
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> a;
		for (int j = 0; j < n; j++) {
			if (a[j] == '*')
				home[i][j] = 2;
			else if (a[j] == '#') {
				home[i][j] = 5;
				if (flag == 0) {
					flag++;
					sx = i;
					sy = j;
					if (sx == 0 && sy > 0) {
						fd = 1;
					}
					else if (sy == 0 && sx > 0) {
						fd = 3;
					}
					else if (sx == n - 1 && sy > 0) {
						fd = 2;
					}
					else if (sy == n - 1 && sx > 0) {
						fd = 4;
					}
				}
				else if (flag == 1) {
					ex = i;
					ey = j;
				}
			}
			else if (a[j] == '!')
				home[i][j] = 1;
		}
	}
	
	bfs(sx, sy, fd);

	if (m == 2500)
		cout << -1 << endl;
	else
		cout << m << endl;

	return 0;
}