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

bool check[1000][1000];
int a[1000][1000];

int main() {
	int test;
	cin >> test;

	for (int t = 0; t < test; t++) {
		int n;
		cin >> n;
		int dir = 1;		// 1-e , 2-w, 3-s, 4-n
		int cnt = 0;
		for (int i = 0; i < 1000; i++) {
			for (int j = 0; j < 1000; j++) {
				a[i][j] = 0;
				check[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			for (int j = n-1; j >0 ; j--) {
				int temp = pow(10, j);
				int b = tmp / temp;
				tmp = tmp % temp;
				a[i][n-j-1] = b;
			}
			a[i][n - 1] = tmp;
		}
		int x = 0;
		int y = 0;
		while(x<n && y<n &&x>=0&&y>=0) {
			if (a[x][y] != 0) {
				if (check[x][y] != true) {
					check[x][y] = true;
					cnt++;
				}
				if (a[x][y] == 1) {
					if (dir == 1) {
						dir = 4;
						x--;
					}
					else if (dir == 2) {
						dir = 3;
						x++;
					}
					else if (dir == 3) {
						dir = 2;
						y--;
					}
					else if (dir == 4) {
						dir = 1;
						y++;
					}
				}
				else if (a[x][y] == 2) {
					if (dir == 1) {
						dir = 3;
						x++;
					}
					else if (dir == 2) {
						dir = 4;
						x--;
					}
					else if (dir == 3) {
						dir = 1;
						y++;
					}
					else if (dir == 4) {
						dir = 2;
						y--;
					}
				}
			}
			else {
				if (dir == 1)
					y++;
				else if (dir == 2)
					y--;
				else if (dir == 3)
					x++;
				else if (dir == 4)
					x--;
			}
		}

		cout << "Case #" << t + 1 << endl << cnt << endl;
	}
}