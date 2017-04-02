#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;
int n, m, k;
long long a[1000001];
long long tree[1000001];

long long sum(long long *tree, int i) {
	long long  ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i&-i);
	}
	return ans;
}

void update(long long *tree, int i, long long diff) {
	while (i <= n) {
		tree[i] += diff;
		i += (i&-i);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	register int i;
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		int diff = a[i];
		update(tree, i, diff);
	}
	m += k;
	while (m--) {
		int tmp1, tmp2;
		scanf("%d %d", &tmp1, &tmp2);
		if (tmp1 == 1) {
			long long tmp3;
			scanf("%lld", &tmp3);
			long long diff = tmp3 - a[tmp2];
			a[tmp2] = tmp3;
			update(tree, tmp2, diff);
		}
		else {
			int tmp3;
			scanf("%d", &tmp3);
			printf("%lld\n", sum(tree, tmp3) - sum(tree, tmp2-1));
		}
	}

	return 0;
}