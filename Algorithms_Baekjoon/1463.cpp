#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int a[1000000];

int cal(int num) {
	int cnt[3] = { 0 };
	if (num == 3)
		return 1;
	else if (num == 2)
		return 1;
	else if (num == 1)
		return 0;
	else if (num % 3 == 0) {
		cnt[0] = cal(num / 3) + 1;
	}
	else if (num % 2 == 0) {
		cnt[1] = cal(num / 2) + 1;
	}
	else {
		cnt[2] = cal(num-1) + 1;
	}
	sort(cnt[0], cnt[2]);

	a[num] = cnt[0];
	return a[num];
}

int main() {
	int test_num;

	scanf("%d", &test_num);

	a[1] = 0;
	a[2] = 1;
	a[3] = 1;

	cal(test_num);

	printf("%d", a[test_num]);

	return 0;
}