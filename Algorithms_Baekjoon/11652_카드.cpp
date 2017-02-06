#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

vector <long long> a;

int main() {
	long long int tmp = 0;
	long long int result = 0;
	int cnt = 1;
	int k;
	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%lld", &tmp);
		a.push_back(tmp);
	}

	sort(a.begin(), a.end());

	int max_cnt = 1;
	for (int i = 1; i < k; i++) {
		if (a[i] == a[i - 1]) {
			cnt++;
		}
		else {
			cnt = 1;
		}
		if (cnt > max_cnt) {
			result = a[i];
			max_cnt = cnt;
		}
	}

	//cout << result << endl;
	printf("%lld\n", result);

	return 0;
}