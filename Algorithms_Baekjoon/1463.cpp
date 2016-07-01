#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int a[1000001];

int main() {
	int test_num;
	for (int i = 0; i < 1000001; i++) {
		a[i] = 1000000;
	}

	a[1] = 0;
	a[2] = 1;
	a[3] = 1;

	for (int i = 4; i < 1000001; i++) {
		if (i % 3 == 0){
			a[i] = a[i / 3] + 1;
		}
		if (i % 2 == 0) {
			if (a[i] > a[i / 2] + 1) {
				a[i] = a[i / 2] + 1;
			}
		}
		if (a[i] > a[i - 1] + 1) {
			a[i] = a[i - 1] + 1;
		}
	}
	while (1) {
		scanf("%d", &test_num);

		printf("%d\n", a[test_num]);
	}
	return 0;
}