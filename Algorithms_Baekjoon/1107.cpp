#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string>
#include <queue>

using namespace std;

bool button[10];

int N, M;

int main() {
	scanf("%d", &N);
	scanf("%d", &M);
	for (int i = 0; i < 10; i++) {
		button[i] = true;
	}
	for (int i = 0; i < M; i++) {
		int tmp;
		scanf("%d", tmp);
		button[tmp] = false;
	}


}