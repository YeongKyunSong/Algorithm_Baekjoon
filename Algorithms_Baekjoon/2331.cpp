#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <queue>
#include <string>
#include <stdlib.h>

using namespace std;

int check[236197];
bool pass[236197];
int cnt = 0;

int main() {
	int A, P;
	scanf("%d %d", &A, &P);

	while (1) {
		int tmp = 0;
		int t = A;
		int temp = 0;

		for (int i = 0; i < 10; i++) {
			temp = t % 10;
			tmp += pow(temp, P);
			t = t / 10;
		}
		if (check[A] == 0&&pass[A]==false) {
			check[A] = cnt;
			pass[A] = true;
			cnt++;
		}
		else
			break;
		A = tmp;
	}
	printf("%d\n", check[A]);

	return 0;
}
