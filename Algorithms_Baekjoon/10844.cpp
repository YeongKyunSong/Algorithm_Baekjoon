#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

long long mod = 1000000000;

long long dp[101][10];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 1; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i < 101; i++) {
		for (int j = 0; j < 10; j++) {
			if (j - 1 >= 0) {
				dp[i][j] += dp[i - 1][j - 1];
			}
			if (j + 1 <= 9) {
				dp[i][j] += dp[i - 1][j + 1];
			}
			dp[i][j] %= mod;
		}
	}

	long long ans = 0;
	for (int i = 0; i < 10; i++) {
		ans += dp[N][i];
	}
	ans %= mod;
	printf("%lld", ans);

	return 0;
}