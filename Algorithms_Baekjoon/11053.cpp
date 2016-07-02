#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

vector<int> dp;
vector<int> a;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		a.push_back(tmp);
		dp.push_back(1);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && dp[j]+1 > dp[i])
				dp[i] = dp[j] + 1;
		}
	}
	int ans;

	ans = *max_element(dp.begin(), dp.end());

	printf("%d", ans);

	return 0;
}