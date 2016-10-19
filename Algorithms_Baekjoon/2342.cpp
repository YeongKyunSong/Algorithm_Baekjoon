#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <string.h>
#include <queue>
#define INF 2000000000;
using namespace std;

vector<int> a;
int x, y;
int ans;
int dp[100001][5][5];
int main() {
	int tmp;
	while (scanf("%d", &tmp)) {
		if (tmp == 0)
			break;
		a.push_back(tmp);
	}

	dp[0][0][0] = 0;
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < 5; j++) {
			if(j==)
		}
	}


	cout << ans << endl;
}