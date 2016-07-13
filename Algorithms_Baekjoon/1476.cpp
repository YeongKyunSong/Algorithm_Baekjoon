#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>

using namespace std;

int main() {
	int e, s, m;
	int E = 1;
	int S = 1;
	int M = 1;
	scanf("%d%d%d", &e, &s, &m);

	for (int i = 1; ; i++) {
		if (e == E&&s == S&&m == M) {
			printf("%d", i);
			return 0;
		}
		E++;
		S++;
		M++;
		if (E > 15)
			E = 1;
		if (S > 28)
			S = 1;
		if (M > 19)
			M = 1;
	}

	return 0;
}