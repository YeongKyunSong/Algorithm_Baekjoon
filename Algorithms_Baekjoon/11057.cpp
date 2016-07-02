#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

#define mod 10007

int dp[1001][10];

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < 10; i++) {
		dp[1][i] = 1;
	}

	for (int i = 2; i < N+1; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				if(j-k >=0)
					dp[i][j] +=  dp[i - 1][j - k] % mod;
			}
		}
	}
	int ans=0;

	for (int i = 0; i < 10; i++) {
		ans += dp[N][i];
	}

	printf("%d", ans%mod);

	return 0;
}