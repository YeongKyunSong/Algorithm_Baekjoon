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

vector<int> v;
vector<int> dp;
int k;

void pre(int start, int end) {
	int min = v[start];
	if (end < v.size()) {
		for (int i = start; i < end; i++) {
			if (min > v[i]) {
				min = v[i];
			}
		}
		dp.push_back(min);
		pre(end, end + k);
	}
	else {
		min = v[start];
		for (int i = start; i < v.size(); i++) {
			if (min > v[i]) {
				min = v[i];
			}
		}
		dp.push_back(min);
	}
}


int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	k = sqrt(n);
	register int i;
	for (i = 0; i < n; i++) {
		int tmp = 0;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}

	pre(0, k);

	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);
		a -= 1;
		b -= 1;

		int na = a / k;
		int nb = b / k;
		int ma = a % k;
		int mb = a % k;
		int min = v[a];
		if (nb - na > 0) {
			for (i = na + 1; i < nb; i++) {
				if (min > dp[i])
					min = dp[i];
			}
			for (i = a; i < k*(na + 1); i++) {
				if (min > v[i])
					min = v[i];
			}
			for (i = k*nb; i < b+1; i++) {
				if (min > v[i])
					min = v[i];
			}
		}
		else {
			for (i = a; i < b+1; i++) {
				if (min > v[i])
					min = v[i];
			}
		}
		

		printf("%d\n", min);
	}
}