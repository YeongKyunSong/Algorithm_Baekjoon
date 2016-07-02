#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

long long int dp[10001][3];
int wine[10001];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 1; i < n+1; i++) {
		int tmp;
		scanf("%d", &tmp);

		wine[i] = tmp;
	}
	dp[1][0] = 0;
	dp[1][1] = wine[1];

	for (int i = 2; i < n + 1; i++) {
		dp[i][0] = max(max(dp[i - 1][2], dp[i - 1][1]),dp[i-1][0]);
		dp[i][1] = dp[i - 1][0] + wine[i];
		dp[i][2] = dp[i - 1][1] + wine[i];
	}
	
	long long int ans = 0;
	ans = max(max(dp[n][0], dp[n][1]), dp[n][2]);

	printf("%lld", ans);

	return 0;
}