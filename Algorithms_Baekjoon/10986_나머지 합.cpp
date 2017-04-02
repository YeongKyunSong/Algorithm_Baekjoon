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
int b[1000001];
long long int c[1000];
long long int ans;

int main() {
	int n, m; 
	cin >> n >> m;
	a[0] = 0;
	b[0] = 0;
	c[0] = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] %= m;
		b[i] = (b[i - 1] + a[i]) % m;
		c[b[i]]++;
	}
	for (int i = 0; i < m; i++) {
		ans += (c[i] * (c[i] - 1))/2;
	}

	cout << ans;

	return 0;
}