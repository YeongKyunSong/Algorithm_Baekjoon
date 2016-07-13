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

int main() {
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	dp.assign(1001, 1);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[i] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
			}
		}
	}

	int ans = *max_element(dp.begin(), dp.end());

	printf("%d", ans);

	return 0;
}