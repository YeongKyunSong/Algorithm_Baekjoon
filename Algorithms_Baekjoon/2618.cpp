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

int dp[1001][1001][2];
vector<pair<int, int>> idx;
int n, m;

void go(pair<int, int> des, int car) {

}

int main() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		idx.push_back(make_pair(x, y));
	}

	go(idx[0], 0);
	go(idx[0], 1);


}