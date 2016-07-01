#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstdio>
#include <stdio.h>

using namespace std;

int index[10001] = { 0 };

int main() {
	int test;
	int tmp;
	cin >> test;

	for (int i = 0; i < test; i++) {
		scanf("%d", &tmp);
		index[tmp]++;
	}

	for (int i = 0; i < 10001; i++) {
		if (index[i] > 0) {
			for (int j = 0; j < index[i]; j++) {
				printf("%d\n", i);
			}
		}
	}

	return 0;
}