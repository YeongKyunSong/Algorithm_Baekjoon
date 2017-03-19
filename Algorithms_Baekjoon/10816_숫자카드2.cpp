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

int main() {
	int n, m;
	cin >> n;
	vector<int> a;

	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end());
	cin >> m;
	vector<int> b;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		auto ans= equal_range(a.begin(), a.end(), tmp);
		cout << ans.second - ans.first << " ";
	}

	return 0;
}