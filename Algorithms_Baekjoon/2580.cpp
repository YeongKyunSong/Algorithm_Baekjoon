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

int s[9][9];
vector<pair<int, int>> zero;
int last;

int chk(int row, int col) {
	for (int i = 0; i < 9; i++) {
		if (i != row) {
			if (s[row][col] == s[i][col])
				return -1;
		}
		if (i != col) {
			if (s[row][col] == s[row][i])
				return -1;
		}
	}
	int x = row / 3 * 3;
	int y = col / 3 * 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (x + i != row&&y + j != col) {
				if (s[x + i][y+j] == s[row][col])
					return -1;
			}
		}
	}
	return 1;
}

void go(int loc) {
	if (loc == last) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << s[i][j] << " ";
			}
			cout << endl;
		}
		exit(0);
	}
		
	for (int i = 1; i < 10; i++) {
		int x = zero[loc].first;
		int y = zero[loc].second;
		s[x][y] = i;
		if (chk(x, y) == 1){
			go(loc + 1);
		}
		s[x][y] = 0;
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			int tmp;
			cin >> tmp;
			s[i][j] = tmp;
			if (tmp == 0) {
				zero.push_back(make_pair(i, j));
				last++;
			}
		}
	}

	go(0);
	
	/*for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}
*/
	return 0;
}