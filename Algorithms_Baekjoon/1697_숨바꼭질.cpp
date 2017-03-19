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

bool check[100001];
int a[100001];

int main() {
	queue<int> q;
	int N, K;
	cin >> N >> K;
	for (int i = 0; i < 100001; i++) {
		a[i] = 100000;
	}

	q.push(N);
	a[N] = 0;
	while(!q.empty()) {
		int tmp = q.front();
		q.pop();
		check[tmp] = true;
		if (tmp + 1 < 100001 && a[tmp]+1<a[tmp+1]) {
			a[tmp + 1] = a[tmp] + 1;
			q.push(tmp + 1);
		}
		if (tmp - 1 >= 0 && a[tmp]+1<a[tmp-1]) {
			a[tmp - 1] = a[tmp] + 1;
			q.push(tmp - 1);
		}
		if (tmp * 2 < 100001&& a[tmp]+1<a[tmp*2]) {
			a[tmp * 2] = a[tmp] + 1;
			q.push(tmp * 2);
		}
	}

	cout << a[K] << "\n";

	return 0;
}