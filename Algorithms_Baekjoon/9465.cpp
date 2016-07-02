#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int board[100000][2];
int dp[100000][3];

int main() {
	int test_case;
	scanf("%d", &test_case);

	for (int t = 0; t < test_case; t++) {
		int n; 
		scanf("%d", &n);
		int tmp;
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			board[i][0] = tmp;
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &tmp);
			board[i][1] = tmp;
		}
		dp[0][0] = 0;
		dp[0][1] = board[0][0];
		dp[0][2] = board[0][1];

		for (int i = 1; i < n; i++) {
			dp[i][0] = max(max(dp[i - 1][0], dp[i - 1][1]), dp[i - 1][2]);
			dp[i][1] =max(dp[i-1][0], dp[i - 1][2]) + board[i][0];
			dp[i][2] = max(dp[i-1][0],dp[i - 1][1]) + board[i][1];
		}
		int ans=0;
		ans = max(max(dp[n - 1][0], dp[n - 1][1]), dp[n - 1][2]);

		printf("%d\n", ans);
	}
	return 0;
}