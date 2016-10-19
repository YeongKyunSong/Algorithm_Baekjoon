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

int N;
int ans;
bool check[15][15];

int chk(int row, int col) {
	for (int i = 0; i < N; i++) {
		if (check[row][i] == 1&& i!=col)
			return -1;
		if (check[i][col] == 1 && i != row)
			return -1;
	}
	for (int i = 1; i < N; i++) {
		if (check[row - i][col - i] == 1 && row - i >= 0 && col - i >= 0)
			return -1;
		if (check[row + i][col + i] == 1 && row + i < N && col + i < N)
			return -1;
		if (check[row - i][col + i] == 1 && row - i >= 0 && col + i < N)
			return -1;
		if (check[row + i][col - i] == 1 && row + i < N && col - i >= 0)
			return -1;
	}
	return 1;
}

void go(int row) {
	if (row == N)
		ans++;
	for (int col=0; col < N; col++) {
		check[row][col] = 1;
		if (chk(row,col)==1) {
			go(row + 1);
		}
		check[row][col] = 0;
	}
}

int main() {
	cin >> N;

	go(0);

	cout << ans << endl;

	return 0;
}