#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

vector <int> a;

int main() {
	int n; 
	int k;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());

	printf("%d\n", a[k-1]);

	return 0;
}