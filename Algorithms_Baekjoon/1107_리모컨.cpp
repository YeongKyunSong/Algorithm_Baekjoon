#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <string>
#include <queue>
#define default 100

using namespace std;

bool button[10];

bool check(int node) {
	while (node >= 1) {
		int tmp = node % 10;
		node /= 10;
		if (button[tmp] == true)
			return false;
	}
	return true;
}

int main() {
	int min = 500000;
	int N, m;
	cin >> N >> m;
	for (int i = 0; i < m; i++) {
		int tmp;
		cin >> tmp;
		button[tmp] = true;
	}

	int ans = 5000000;
	min = abs(N - 100);
	ans = abs(N - 100);
	int len = 1;
	
	if (button[0] == false) {
		if (N < min) {
			min = N;
			ans = min + 1;
		}
	}

	for (int i = 1; i < 1000000; i++) {
		if (check(i)) {
			len = 0;
			int tmp = i;
			while (tmp >= 1) {
				len++;
				tmp /= 10;
			}
			if (min > abs(N - i)) {
				min = abs(N - i);
				if(ans > len+min)
					ans = len + min;
			}
		}
	}
	cout << ans << "\n";

	return 0;
}