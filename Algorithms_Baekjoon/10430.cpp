/*https://www.acmicpc.net/problem/10430 ³ª¸ÓÁö*/

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

int main() {
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	cout << (a + b) % c << endl;
	cout << (a%c + b%c) % c << endl;
	cout << (a*b) % c << endl;
	cout << ((a%c)*(b%c)) % c << endl;

	return 0; 
}