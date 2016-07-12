#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

int a, p;
int d[1000001];
int chk[1000001];
int ans;

void go(int n, int idx)
{
	d[idx] = n;
	chk[n] = idx;

	int sum = 0;
	while (n != 0)
	{
		int a = n % 10;
		sum += pow(a, p);
		n = n / 10;
	}

	if (chk[sum] == false)
		go(sum, idx + 1);
	else
		ans = chk[sum];

	return;
}


int main()
{
	cin >> a >> p;


	go(a, 1);

	cout << ans - 1 << "\n";
}