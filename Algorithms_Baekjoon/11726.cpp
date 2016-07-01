#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

int pibo[1001];

int main() {
	int n;
	scanf("%d", &n);

	pibo[0] = 1;
	pibo[1] = 1;

	for (int i = 2; i < 1001; i++) {
		pibo[i] = (pibo[i - 1] + pibo[i - 2])%10007;
	}

	printf("%d\n", pibo[n]%10007);

	return 0;

}