#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>
#include <string>

#define min(a,b) a<b?a:b
#define max(a,b) a>b?a:b

using namespace std;

vector<int> v;
vector<int> dp;
int chk1[100001][17];
int chk2[100001][17];

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		chk1[i][0] = v[i];
		chk2[i][0] = v[i];
	}
	for (int j = 1; j < 17; j++) {
		for (int i = 0; i < n; i++) {
			if (i + (1 << j) - 1 < n) {
				chk1[i][j] = min(chk1[i][j - 1], chk1[i + (1 << (j - 1))][j - 1]);
				chk2[i][j] = max(chk2[i][j - 1], chk2[i + (1 << (j - 1))][j - 1]);
			}
		}
	}

	while (m--) {
		int a, b;
		scanf("%d %d", &a, &b);

		int MIN = v[a-1];
		int MAX = v[a-1];

		a -= 1;
		b -= 1;
		int k = 16;
		while (a <= b &&k >= 0) {
			if (a + (1 << k) - 1 <= b) {
				MIN = min(MIN, chk1[a][k]);
				MAX = max(MAX, chk2[a][k]);
				a += (1 << k);
			}
			k -= 1;
		}

		printf("%d %d\n", MIN, MAX);
	}
	return 0;
}