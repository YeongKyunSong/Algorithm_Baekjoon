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

int calculate(vector<int> &a) {
	int sum = 0;
	for (int i = 1; i < a.size(); i++) {
		sum += abs(a[i] - a[i - 1]);
	}
	return sum;
}

int main() {
	int N;
	scanf("%d", &N);

	vector<int> a(N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &a[i]);
	}

	sort(a.begin(), a.end());
	
	int ans = 0;

	do {
		int temp = calculate(a);
		ans = max(ans, temp);
	} while (next_permutation(a.begin(), a.end()));

	printf("%d", ans);

	return 0;
}