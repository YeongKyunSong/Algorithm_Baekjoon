#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main() {
	queue<int> q;

	int a, b;

	cin >> a >> b;

	for (int i = 1; i < a + 1; i++) {
		q.push(i);
	}

	cout << "<";
	while (!q.empty())
	{
		for (int j = 0; j < b - 1; j++) {
			int tmp = q.front();
			q.pop();
			q.push(tmp);
		}
		cout << q.front();
		q.pop();
		if (q.empty())
			break;
		cout << ", ";
	}
	cout << ">" << endl;

	return 0;
}