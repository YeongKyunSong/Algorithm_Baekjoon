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

vector<int> a;

int main() {
	int n; 
	while (1){
		cin >> n;
		if (n == 0) {
			break;
		}
		vector<int> first;
		for (int i = 0; i < n; i++) {
			int tmp;
			cin >> tmp;
			first.push_back(tmp);
		}

		vector<int> a;
		for (int i = 0; i < n - 6; i++) {
			a.push_back(0);
		}
		for (int i = 0; i < 6; i++) {
			a.push_back(1);
		}
		int cnt = 0;
		vector<vector<int>> ans;
		do {
			vector<int> tmp;
			for (int i = 0; i < n; i++) {
				if (a[i] == 1) {
					tmp.push_back(first[i]);
				}
			}
			ans.push_back(tmp);
			cnt++;
		} while (next_permutation(a.begin(), a.end()));
		for (int i = 0; i< cnt; i++) {
			sort(ans.begin(), ans.end());
		}

		for (int i = 0; i < cnt; i++) {
			for (int j = 0; j < 6; j++) {
				cout << ans[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}