#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

vector<int> a[1001];
bool check[1001];
int dp[1101];

int n;
int cnt;
int ans = 2000000000;
	
void dfs(int l) {
	if (l >= n-1) {
		if (dp[l] < ans) {
			ans = dp[l];
		}
	}
	else {
		for (int i = 1; i <= a[l][0]; i++) {
			if (check[l + i] == 1) {
				if (dp[l + i] > dp[l] + 1) {
					dp[l + i] = dp[l] + 1;
					dfs(l + i);
				}
			}
			else {
				check[l + i] = 1;
				dp[l + i] = dp[l] + 1;
				dfs(l + i);
			}
		}
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		a[i].push_back(tmp);
	}
	dfs(0);

	if (ans == 2000000000)
		ans = -1;

	cout << ans << endl;

	return 0;
}