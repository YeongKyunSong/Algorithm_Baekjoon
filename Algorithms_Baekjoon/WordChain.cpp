#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cstdio>
#include <string.h>
#include <string>
#include <queue>
#define default 100

using namespace std;

struct node {
	int num;
	string name;
	node() {
		num = default;
	}
};

vector<node> a[101];
string str[101];
int check[101][101];
queue<string> q;
int cnt;
bool flag;
int n;

void dfs(node node, int c) {
	int tail = node.num;
	string s = node.name;
	q.push(s);
	if (c == n-1) {
		while (!q.empty()) {
			cout << q.front() << " ";
			q.pop();
		}
		flag = true;
	}
	if (flag == false) {
		for (int i = 0; i < a[tail].size(); i++) {
			if (check[tail][a[tail][i].num] > 0) {
				c++;
				check[tail][a[tail][i].num]--;
				dfs(a[tail][i], c);
				check[tail][a[tail][i].num]++;
				if (!q.empty())
					q.pop();
				c--;
			}
		}
	}
}

int main() {
	int c;
	scanf("%d", &c);
	while (c--) {
		memset(check, 0, sizeof(check));
		for (int i = 0; i < 101; i++) {
			a[i].clear();
			str[i] = "";
		}
		flag = false;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			string s;
			node tmp;
			cin >> s;
			int tmp1 = s[0] - 97;
			int tmp2 = s[s.size() - 1] - 97;
			tmp.num = tmp2;
			tmp.name = s;
			check[tmp1][tmp2]++;
			a[tmp1].push_back(tmp);
		}
		for (int i = 0; i < n; i++) {
			cnt = 0;
			while (!q.empty()) {
				q.pop();
			}
			if (a[i].size() != 0 && flag==false) {
				for (int j = 0; j < a[i].size(); j++) {
					check[i][a[i][j].num]--;
					dfs(a[i][j], cnt);
					check[i][a[i][j].num]++;
				}
			}
		}
		if (flag == false)
			cout << "IMPOSSIBLE";

		cout << "\n";
	}
	return 0;
}