#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int a[1001];
int d[1001];

int go(int n) {

	if (d[n] > 0)
		return d[n];

	for (int i = 1; i <= n; i++)
	{
		int tmp = go(n - i) + a[i];
		if (d[n] < tmp)
			d[n] = tmp;
	}

	return d[n];
}

int main() {
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int tmp;
		scanf("%d", &tmp);
		a[i + 1] = tmp;
	}
	d[0] = 0;
	d[1] = a[1];
	printf("%d\n", go(N));

	return 0;
}