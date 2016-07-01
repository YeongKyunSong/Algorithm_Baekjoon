#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int a[12];

int go(int n) {
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	if (n == 3)
		return 4;
	if (a[n] > 0)
		return a[n];
	else {
		a[n] = go(n - 1) + go(n - 2) + go(n - 3);
		return a[n];
	}
}

int main() {
	int n;
	int test_case;
	scanf("%d", &test_case);
	for (int t = 0; t < test_case; t++) {

	
	scanf("%d", &n);

	printf("%d\n" ,go(n));

	}
	return 0;
}