#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

long long int dp[201][201];
int mod = 1000000000;

int main() {
	int n, k;
	scanf("%d %d", &n, &k);

	dp[0][0] = 1;
	for (int i = 1; i <= k; i++) {
		for (int j = 0; j <= n; j++) {
			for (int l = 0; l <= j; l++) {
				dp[i][j] += dp[i - 1][j - l];
				dp[i][j] %= mod;
			}
		}
	}

	cout << dp[k][n] << endl;

	return 0;
}