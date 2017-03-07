#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

vector<int> a;
vector<int> dp;

int main() {
	int n; 
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		a.push_back(tmp);
		dp.push_back(tmp);
	}

	for (int i = 0; i < n-1; i++) {
		if (dp[i] + dp[i + 1] > dp[i + 1]) {
			dp[i + 1] = dp[i] + dp[i + 1];
		}
	}
	int ans;
	ans = *max_element(dp.begin(), dp.end());

	cout << ans;

	return 0;
}