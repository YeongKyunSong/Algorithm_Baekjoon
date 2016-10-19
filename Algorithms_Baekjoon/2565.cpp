#include <iostream>
#include <algorithm>
using namespace std;

struct line {
	int a;
	int b;
};

line a[101];
int d[101];

bool linecmp(line a, line b)
{
	return a.a < b.a;
}

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
		cin >> a[i].a >> a[i].b;

	sort(a, a + n, linecmp);

	for (int i = 0; i < n; i++)
	{
		d[i] = 1;
		for (int j = 0; j <= i; j++)
		{
			if (a[j].b <a[i].b && d[j] + 1 > d[i])
			{
				d[i] = d[j] + 1;
			}
		}
	}

	int maxi = 0;
	for (int i = 0; i < n; i++)
	{
		if (maxi < d[i])
			maxi = d[i];
	}

	cout << n - maxi << endl;
}