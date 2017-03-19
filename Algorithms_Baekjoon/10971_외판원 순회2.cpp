#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

int a[20][20];

int main() {	
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &a[i][j]);
		}
	}

	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		b[i] = i;
	}
	int ans = 10000000000;
	do {
		bool ok = true;
		int sum = 0;
		for (int i = 0; i < n-1; i++) {
			if (a[b[i]][b[i + 1]] == 0)
				ok = false;
			else
				sum += a[b[i]][b[i + 1]];
		}
		if (ok&&a[b[n - 1]][b[0]]!=0) {
			sum += a[b[n - 1]][b[0]];
			if (ans > sum)ans = sum;
		}
	} while (next_permutation(b.begin(), b.end()));

	cout << ans << endl;

	return 0;
}
