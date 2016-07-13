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

vector<int> dp;
int a[1001];
int N;

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}
	dp.assign(1000, 0);
	for (int i = 0; i < N; i++) {
		dp[i] = a[i];
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && dp[j] + a[i] > dp[i]) {
				dp[i] = dp[j] + a[i];
			}
		}
	}

	int ans = *max_element(dp.begin(), dp.end());

	printf("%d", ans);

	return 0;
}