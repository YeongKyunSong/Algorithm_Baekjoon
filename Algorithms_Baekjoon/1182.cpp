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

int N, S;
vector<int> a;
int ans;
bool check[20];

void dfs(int cur, int cnt) {
	if (cur == N) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			if (check[i] == true) {
				sum += a[i];
			}
		}
		if (sum == S && cnt != 0)
			ans++;
		return;
	}

	check[cur] = true;
	dfs(cur + 1, cnt+1);
	check[cur] = false;
	dfs(cur + 1, cnt);
}

int main() {
	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		a.push_back(tmp);
	}

	ans = 0;

	dfs(0, 0);

	cout << ans << endl;

	return 0;
}