#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <string>
#include <queue>

using namespace std;

bool chk[201][201];
bool ans[201];

int main() {
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	int a1, b1, c1;
	a1 = 0;
	b1 = 0;
	c1 = C;
	queue<pair<int, int>> q;
	chk[a1][b1] = true;
	pair<int, int> tmp;
	tmp.first = a1;
	tmp.second = b1;
	q.push(tmp);
	ans[c1] = true;
	
	while (!q.empty()) {
		pair<int, int> now = q.front();
		q.pop();
		int a = now.first;
		int b = now.second;
		int c = C - a - b;

		a += b;
		b = 0;
		if (a - A >= 0) {
			b = a - A;
			a = A;
		}
		if (chk[a][b] == false) {
			chk[a][b] = true;
			if (a == 0)
				ans[c] = true;
			pair<int, int> tmp;
			tmp.first = a;
			tmp.second = b;
			q.push(tmp);
		}
		a = now.first;
		b = now.second;
		c = C - a - b;
		a += c;
		c = 0;
		if (a - A >= 0) {
			c = a - A;
			a = A;
		}
		if (chk[a][b] == false) {
			chk[a][b] = true;
			if (a == 0)
				ans[c] = true;
			pair<int, int> tmp;
			tmp.first = a;
			tmp.second = b;
			q.push(tmp);
		}
		a = now.first;
		b = now.second;
		c = C - a - b;
		b += a;
		a = 0;
		if (b - B >= 0) {
			a = b - B;
			b = B;
		}
		if (chk[a][b] == false) {
			chk[a][b] = true;
			if (a == 0)
				ans[c] = true;
			pair<int, int> tmp;
			tmp.first = a;
			tmp.second = b;
			q.push(tmp);
		}
		a = now.first;
		b = now.second;
		c = C - a - b;
		b += c;
		c = 0;
		if (b - B >= 0) {
			c = b - B;
			b = B;
		}
		if (chk[a][b] == false) {
			chk[a][b] = true;
			if (a == 0)
				ans[c] = true;
			pair<int, int> tmp;
			tmp.first = a;
			tmp.second = b;
			q.push(tmp);
		}
		a = now.first;
		b = now.second;
		c = C - a - b;
		c += a;
		a = 0;
		if (c - C >= 0) {
			a = c - C;
			c = C;
		}
		if (chk[a][b] == false) {
			chk[a][b] = true;
			if (a == 0)
				ans[c] = true;
			pair<int, int> tmp;
			tmp.first = a;
			tmp.second = b;
			q.push(tmp);
		}
		a = now.first;
		b = now.second;
		c = C - a - b;
		c += b;
		b = 0;
		if (c - C >= 0) {
			b = c - C;
			c = C;
		}
		if (chk[a][b] == false) {
			chk[a][b] = true;
			if (a == 0)
				ans[c] = true;
			pair<int, int> tmp;
			tmp.first = a;
			tmp.second = b;
			q.push(tmp);
		}
	}
	for (int i = 0; i < 201; i++) {
		if (ans[i] == true) {
			printf("%d ", i);
		}
	}

	return 0;
}