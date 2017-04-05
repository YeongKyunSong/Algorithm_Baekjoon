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

int a[10001];
int k, n;

int check(int tmp) {
	int ans = 0;
	for (int i = 0; i < k; i++) {
		ans += a[i] / tmp;
	}
	return ans;
}

int main() {
	scanf("%d %d", &k, &n);

	register int i;
	int max = 0;
	for (i = 0; i < k; i++) {
		scanf("%d", &a[i]);
		if (max < a[i])
			max = a[i];
	}

	long long start = 1;
	long long end = max;
	long long ans=0;
	while (start <= end) {
		long long mid = (start + end) / 2;

		if (check(mid) >= n) {
			if (ans < mid) {
				ans = mid;
			}
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}

	cout << ans << "\n";

	return 0;
}