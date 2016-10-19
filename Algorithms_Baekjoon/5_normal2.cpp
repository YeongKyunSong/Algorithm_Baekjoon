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

bool dp[3][100001];

int main() {
	int test;
	cin >> test;

	for (int t = 0; t < test; t++) {
		vector<int> a;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 100001; j++) {
				dp[i][j] = 0;
			}
		}
		int n;
		int cnt = 0;
		cin >> n;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			a.push_back(tmp);
			dp[0][tmp] = 1;
			if (tmp * 2 <= 100000)
				dp[1][tmp*2] = 1;
			if (tmp * 3 <= 100000)
				dp[2][tmp*3] = 1;

			for (int j = 1; j <= i+1; j++) {
				if (j + tmp <= 100000 && dp[1][j] == true)
					dp[2][j + tmp] = true;
				if (j + tmp <= 100000 && dp[0][j] == true)
					dp[1][j + tmp] = true;
				if (j + tmp * 2 <= 100000 && dp[0][j] == true)
					dp[2][j + tmp * 2] = true;
			}
			if (dp[2][tmp] == true)
				cnt++;
		}

		cout << "Case #" << t+1 << endl << cnt << endl;
	}

	return 0;
}