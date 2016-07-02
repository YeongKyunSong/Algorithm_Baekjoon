#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

long long int dp[91][2];

int main() {
	int N;
	scanf("%d", &N);

	dp[1][1] = 1;

	for (int i = 2; i < N + 1; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}

	long long int ans;

	ans = dp[N][0] + dp[N][1];

	printf("%lld", ans);

	return 0;
}