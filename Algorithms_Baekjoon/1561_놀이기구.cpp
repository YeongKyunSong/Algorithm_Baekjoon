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

int N, M;
int a[10001];
bool b[10001];

int main() {
	scanf("%d %d", &N, &M);
	register int i;
	long long max = 0;
	for (i = 0; i < M; i++) {
		scanf("%d", &a[i]);
		if (max < a[i])
			max = a[i];
	}
	if (M >= N) {
		cout << N << endl;
		return 0;
	}
	long long left = 1;
	long long right = max*N;
	long long ans = max*N;
	long long number = 0;
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long num = 0;
		for (int i = 0; i < M; i++) {
			if (mid%a[i] == 0)
				num += mid / a[i];
			else
				num += mid / a[i] + 1;
		}
		if (num >= N) {
			if (ans > mid) {
				ans = mid;
				number = num;
			}
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	for (int i = M; i > 0; i--) {
		if ((ans - 1) % a[i-1] == 0) {
			if (number == N) {
				cout << i << endl;
				return 0;
			}
			else
				number -= 1;
		}
	}

	return 0;
}