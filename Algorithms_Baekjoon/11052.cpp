#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int a[1001];
vector<int> P;

int go(int n) {
	if (n == 1)
		return a[1];
	if (a[n] > P[n-1])
		return a[n];
	else {
		for (int i = 1; i < n; i++) {
			int tmp = go(n - i) + go(i);
			if (a[n] < tmp) {
				a[n] = tmp;
			}
		}
		return a[n];
	}
}

int main() {
	int N;
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			int tmp;
			scanf("%d", &tmp);
			P.push_back(tmp);
			a[i+1] = P[i];
		}
		printf("%d\n", go(N));

	return 0;
}