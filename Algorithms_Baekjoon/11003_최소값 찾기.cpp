#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>
#include <string>

using namespace std;

int a[5000000];

int main() {
	int n, l;
	cin >> n >> l;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	deque<pair<int, int> > d;
	vector<int> ans(n);
	for (int i = 0; i < n; i++) {
		int cur = a[i];
		if (!d.empty() && d.front().second <= i - l) {
			d.pop_front();
		}
		while (!d.empty() && d.back().first > cur) {
			d.pop_back();
		}
		d.push_back(make_pair(cur, i));
		ans[i] = d.front().first;
	}
	for (int i = 0; i < n; i++) {
		printf("%d ", ans[i]);
	}

	return 0;
}