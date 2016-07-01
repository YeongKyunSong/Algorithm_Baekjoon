#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main()
{
	int sum, min;

	int x, y;
	cin >> sum >> min;

	x = (sum + min) / 2;
	y = sum - x;

	if ((sum + min) % 2 != 0 || sum < min)
	{
		cout << -1;
		return -1;
	}
	if (x > y)
	{
		cout << x << " " << y;
	}
	else
	{
		cout << y << " " << x;
	}

	return 0;
}