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

int dp[301][2];	// 0 = 1Ä­ 1= 2Ä­ 2= Á¡ÇÁ
int a[300];
int n;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a[i] = tmp;
	}
	dp[1][0] = a[0];
	dp[2][1] = a[1];
	dp[2][0] = a[0] + a[1];

	for (int i = 3; i <= n; i++) {
		dp[i][0] = dp[i-1][1] + a[i - 1];
		dp[i][1] = max(dp[i - 2][1], dp[i - 2][0]) + a[i - 1];
	}
	cout << max(dp[n][0], dp[n][1]) << endl;

	return 0;
}