#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

int a[15][15];
int cnt;
int n;
bool check[15];
bool l[40];
bool r[40];

bool chk(int row, int col) {
	if (check[col])
		return false;
	else if (l[row + col])
		return false;
	else if (r[row - col + n])
		return false;
	else
		return true;
}

void go(int row) {
	if (row == n) {
		cnt++;
		return;
	}
	for (int i = 0; i < n; i++) {
		if (chk(row, i)) {
			check[i] = true;
			l[row + i] = true;
			r[row - i + n] = true;
			go(row + 1);
			check[i] = false;
			l[row + i] = false;
			r[row - i + n] = false;
		}
	}
}

int main() {
	for (int i = 0; i < 15; i++) {
		check[i] = false;
	}
	for (int i = 0; i < 40; i++) {
		l[i] = false;
		r[i] = false;
	}

	scanf("%d", &n);

	go(0);

	cout << cnt << endl;

	return 0;
}