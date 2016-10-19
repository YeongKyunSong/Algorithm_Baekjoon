#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<queue>
#include<string.h>
#include<vector>

using namespace std;

vector<int> a;

bool chk(vector<long long int> &a, long long int mid, int target) {
	long long int n = a.size();
	long long int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] / mid;
	}
	if (sum < target)
		return true;
	else
		return false;
}
long long int min(long long int a, long long int b) {
	if (a > b)
		return b;
	else
		return a;
}
long long int max(long long int a, long long int b) {
	if (a > b)
		return a;
	else
		return b;
}

int main() {
	long long int k, n;
	cin >> k >> n;

	vector<long long int> v(k);

	long long int maxi = 0;

	for (int i = 0; i < k; i++) {
		cin >> v[i];
	}

	long long int left = 0;
	long long int right = maxi;
	long long int ans = 0;
	while (left <= right) {
		long long int mid = left + (right - left) / 2;
		if (chk(v, mid, n)) {
			right = mid + 1;
		}
		else {
			left = mid + 1;
			ans = max(mid, ans);
		}
	}

	cout << ans << endl;
}