#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string left;
	string right;

	cin >> left;

	int test;
	cin >> test;

	for (int i = 0; i < test; i++) {
		char order;
		char a;
		cin >> order;

		if (order == 'L') {
			if (left.size() != 0) {
				right.push_back(left.at(left.size() - 1));
				left.pop_back();
			}
		}
		else if (order == 'D') {
			if (right.size() != 0) {
				left.push_back(right.at(right.size() - 1));
				right.pop_back();
			}
		}
		else if (order == 'B') {
			if (left.size() != 0)
				left.pop_back();
		}
		else if (order == 'P') {
			char tmp;
			cin >> tmp;

			left.push_back(tmp);
		}
	}
	std::reverse(right.begin(), right.end());
	cout << left << right << endl;

	return 0;
}