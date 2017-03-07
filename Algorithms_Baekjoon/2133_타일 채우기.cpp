#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

int dp[31];

int main() {
	int n;
	scanf("%d", &n);
	dp[0] = 1;
	dp[2] = 3;
	dp[4] = 11;

	for (int i = 6; i < 31; i+=2) {
		dp[i] = dp[i - 2] * 3;
		for (int j = 4; j <= i; j+=2) {
			dp[i] += dp[i - j] * 2;
		}
	}

	cout << dp[n] << endl;

	return 0;
}