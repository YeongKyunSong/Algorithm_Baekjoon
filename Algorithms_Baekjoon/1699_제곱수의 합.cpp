#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

int d[100001];

int main() {
	int n; 
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		d[i] = i;
		for (int j = 1; j*j <= i; j++) {
			if (d[i] > d[i - j*j] + 1)
				d[i] = d[i - j*j] + 1;
		}
	}

	cout << d[n];

	return 0;
}