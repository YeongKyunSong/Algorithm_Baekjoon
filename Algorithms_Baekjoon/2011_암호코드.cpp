#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <string>
#include <queue>

using namespace std;

long long dp[5001];
char str[5001];
int mod = 1000000;

int main() {
	cin >> str;
	int n = 0;
	
	while (str[n] != NULL) {
		n++;
	}
	
	dp[0] = 1;
	if (str[0] == '0')
		dp[0] = 0;
	dp[1] = 1;
	int tmp = str[1] - '0' + (str[0] - '0') * 10;
	if (tmp == 10 || tmp == 20) {
		dp[1] = 1;
	}
	else if (tmp > 10 && tmp < 27) {
		dp[1] = 2;
	}
	for (int i = 2; i < n; i++) {
		int tmp = str[i] - '0';
		if (tmp > 0 && tmp < 10) {
			dp[i] += dp[i - 1];
			dp[i] %= mod;
		}

		if (str[i - 1] == '0')
			continue;
		tmp = (str[i - 1] - '0') * 10 + str[i]-'0';
		if (tmp > 9 && tmp < 27) {
			dp[i] += dp[i - 2];
			dp[i] %= mod;
		}
	}

	cout << dp[n-1];

	return 0;
}