#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

vector<int> a;
vector<int> dp1;
vector<int> dp2;
vector<int> dp3;

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int tmp;
		scanf("%d", &tmp);
		a.push_back(tmp);
		dp1.push_back(1);
		dp2.push_back(1);
		dp3.push_back(1);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j] && dp1[j] + 1 > dp1[i])
				dp1[i] = dp1[j] + 1;
		}
	}
	for (int i = n-1; i >=0; i--) {
		for (int j = n-1; j > i; j--) {
			if (a[i] > a[j] && dp2[j] + 1 > dp2[i])
				dp2[i] = dp2[j] + 1;
		}
	}

	for (int i = 0; i < dp1.size(); i++) {
		dp3[i] = dp1[i] + dp2[i];
	}

	int ans;
	ans = *max_element(dp3.begin(), dp3.end());

	cout << ans-1;

	return 0;
}