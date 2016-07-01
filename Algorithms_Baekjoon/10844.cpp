#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int dp[101];

int main() {
	int N;
	scanf("%d", &N);

	dp[1] = 9;
	dp[2] = 17;

	for (int i = 3; i < 101; i++) {
		dp[i] = (dp[i - 1] * 2 - 3)%1000000000;
	}

	printf("%d", dp[N]);
}