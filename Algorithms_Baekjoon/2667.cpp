#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>

using namespace std;

int a[25][25];
int step[25][25];
vector<int> number;
int cnt;

void dfs(int f, int t, int s) {
	step[f][t] = s;
	//cnt++;
	if (f - 1 >= 0) {
		if (a[f - 1][t] > 0 && step[f - 1][t] == 0) {
			dfs(f - 1, t, s);
		}
	}
	if (t - 1 >= 0) {
		if (a[f][t - 1] > 0 && step[f][t - 1] == 0) {
			dfs(f , t-1, s);
		}
	}
	if (f + 1 <= 24){
		if (a[f + 1][t] > 0 && step[f + 1][t] == 0) {
			dfs(f + 1, t, s);
		}
	}
	if (t + 1 <= 24) {
		if (a[f][t + 1] > 0 && step[f][t + 1] == 0) {
			dfs(f , t+1, s);
		}
	}
}

int main() {
	int N;
	scanf("%d", &N);
	int s = 1;

	for (int i = 0; i < N; i++) {
		int tmp;
		for (int j = 0; j < N; j++) {
			scanf("%1d", &tmp);
			a[i][j] = tmp;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (step[i][j]==0 && a[i][j] > 0) {
				dfs(i, j, s);
				s++;
				//number.push_back(cnt);
				//cnt = 0;
			}
		}
	}

	number.assign(s-1, 0);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if(step[i][j]!=0)
				number[step[i][j]-1]++;
		}
	}

	sort(number.begin(), number.end());

	printf("%d\n", number.size());

	for (int i = 0; i < number.size(); i++) {
		printf("%d\n", number[i]);
	}

	return 0;
}