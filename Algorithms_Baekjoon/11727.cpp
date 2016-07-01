#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int n[1001];

int main() {
	int a = 0;
	scanf("%d", &a);

	n[0] = 1;
	n[1] = 1;

	for (int i = 2; i < 1001; i++) {
		n[i] = (n[i - 1] + n[i - 2] * 2)%10007;
	}

	printf("%d", n[a]);
}