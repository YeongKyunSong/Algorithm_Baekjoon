#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <string>
#include <queue>

using namespace std;

bool prime[10001];
bool chk[10001];
int dp[10001];

int change(int node, int pos, int digit) {
	if (pos == 0 && digit == 0) return -1;
	string s = to_string(node);
	s[pos] = digit + '0';

	return stoi(s);
}

int main() {
	prime[0] = true;
	prime[1] = true;
	for (int i = 2; i < 10001; i++) {
		if (prime[i] == false) {
			for (int j = i*i; j < 10001; j+=i) {
				prime[j] = true;
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {
		memset(dp, 0, sizeof(dp));
		memset(chk, false, sizeof(chk));
		int tmp1, tmp2;
		cin >> tmp1 >> tmp2;

		queue<int> q;
		q.push(tmp1);
		dp[tmp1] = 0;
		chk[tmp1] = true;
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			for (int i = 0; i <4; i++) {
				for (int j = 0; j <= 9; j++) {
					int next = change(now, i, j);
					if (next != -1) {
						if (chk[next] == false && prime[next] == false) {
							q.push(next);
							chk[next] = true;
							dp[next] = dp[now] + 1;
						}
					}	
				}
			}

		}
		if (tmp1 != tmp2 && dp[tmp2] == 0)
			cout << "Impossible" << endl;
		else
			cout << dp[tmp2] << endl;
	}

	return 0;
}