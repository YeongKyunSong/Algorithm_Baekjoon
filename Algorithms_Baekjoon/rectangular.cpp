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

struct info {
	int x1;
	int y1;
	int x2;
	int y2;
	info(int x1, int y1, int x2, int y2) :x1(x1), y1(y1), x2(x2), y2(y2) {
	}
};

vector<info> a;
int N, M, K;

int dp[5001];

int dfs(int cur, int cnt) {
	if (dp[cur] > 0) {
		return dp[cur];
	}

	dp[cur] = cnt;
	int sum = dp[cur];

	for (int i = 0; i < K; i++) {
		if (a[cur].x1 <= a[i].x1&&a[cur].y1 <= a[i].y1&&a[cur].x2 >= a[i].x2&&a[cur].y2 >= a[i].y2 && (cur!=i) ){
			int x = dfs(i, cnt);
			if (sum < x + dp[cur]) {
				sum = x + dp[cur];
			}
		}
	}
	dp[cur] = sum;
	return dp[cur];
}

int main() {
	int test;
	cin >> test;
	for (int t = 0; t < test; t++) {
		memset(dp, 0, sizeof(dp));
		int ans = 0;
		a.clear();
		cin >> N >> M>> K;
		for (int i = 0; i < K; i++){
			info tmp(0,0,0,0);
			cin >> tmp.x1 >> tmp.y1 >> tmp.x2 >> tmp.y2;
			a.push_back(tmp);
		}
		for (int i = 0; i < K; i++) {
			ans = max(ans, dfs(i, 1));
		}
		cout << "Case #" << t + 1 << endl <<  ans << endl;
	}
	return 0;
}