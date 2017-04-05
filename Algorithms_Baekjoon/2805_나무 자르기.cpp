#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>
#include <string>

using namespace std;

int a[1000001];
int N, M;

bool check(int tmp) {
	long long ans = 0;
	for (int i = 0; i < N; i++) {
		if (a[i] - tmp > 0)
			ans += a[i] - tmp;
	}
	return ans >= M;
}

int main() {
	scanf("%d %d", &N, &M);
	register int i;
	register int max = 0;
	for (i = 0; i < N; i++) {
		scanf("%d", &a[i]);
		if (max < a[i])
			max = a[i];
	}
	long long start = 1;
	long long end = max;
	long long ans = 0;
	while (start <= end) {
		long long mid = (start + end) / 2;
		if (check(mid)) {
			if (ans < mid)
				ans = mid;
			start = mid + 1;
		}
		else
			end = mid - 1;
	}
	cout << ans;

	return 0;
}