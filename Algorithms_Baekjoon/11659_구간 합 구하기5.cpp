#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

int a[100001];
long long int dp[100001][17];

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		dp[i][0] = a[i];
	}
	for (int j = 1; j < 17; j++) {
		for (int i = 1; i <= n; i++) {
			if(i + (1 << j)-1 <= n)
				dp[i][j] = dp[i][j - 1] + dp[i + (1 << j - 1)][j - 1];
		}
	}



	for (int i = 0; i < m; i++) {
		int start, end;
		scanf("%d %d", &start, &end);
		
		int k = 16;
		long long int ans = 0;
		while (k >= 0&& start<=end) {
			if (start + (1 << k)-1 <= end) {
				ans += dp[start][k];
				start += (1 << k);
			}
			k -= 1;
		}
		printf("%lld\n", ans);
	}

	return 0;
}