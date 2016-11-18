/*https://www.acmicpc.net/problem/2609 최대공약수와 최소공배수*/
/*유클리드 호제법 사용*/
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

int gcd(int a, int b) {
	return b ? gcd(b, a%b) : a;
}

int lcm(int g, int a, int b) {
	int A = a / g;
	int B = b / g;
	
	return A*B*g;
}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);

	cout << gcd(a, b) << endl << lcm(gcd(a, b), a, b) << endl;
}