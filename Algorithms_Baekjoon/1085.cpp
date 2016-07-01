#include <stdio.h>
#include <math.h>
#include <string.h>

int pibonacci(int n);

int main()
{
	int tmp[4] = { 0 };
	int x, y, w, h;
	int i;
	int result = 0;

	scanf("%d %d %d %d", &x, &y, &w, &h);

	tmp[0] = w - x;
	tmp[1] = h - y;
	tmp[2] = x;
	tmp[3] = y;
	result = tmp[0];
	for (i = 0; i < 4; i++)
	{
		if (tmp[i]<result)
		{
			result = tmp[i];
		}
	}

	printf("%d", result);
}
