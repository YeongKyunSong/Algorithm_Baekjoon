#include<stdio.h>
#include<math.h>

int main()
{
	int i = 0;
	int T = 0;

	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		int a = 0;
		int b = 0;
		int result = 1;
		scanf("%d %d", &a, &b);

		if (a % 10 == 1)
			result = 1;
		else if (a % 10 == 2)
		{
			if (b % 4 == 1)
				result = 2;
			if (b % 4 == 2)
				result = 4;
			if (b % 4 == 3)
				result = 8;
			if (b % 4 == 0)
				result = 6;
		}
		else if (a % 10 == 3)
		{
			if (b % 4 == 1)
				result = 3;
			if (b % 4 == 2)
				result = 9;
			if (b % 4 == 3)
				result = 7;
			if (b % 4 == 0)
				result = 1;
		}
		else if (a % 10 == 4)
		{
			if (b % 2 == 1)
				result = 4;
			if (b % 2 == 0)
				result = 6;
		}
		else if (a % 10 == 5)
			result = 5;
		else if (a % 10 == 6)
			result = 6;
		else if (a % 10 == 7)
		{
			if (b % 4 == 1)
				result = 7;
			if (b % 4 == 2)
				result = 9;
			if (b % 4 == 3)
				result = 3;
			if (b % 4 == 0)
				result = 1;
		}
		else if (a % 10 == 8)
		{
			if (b % 4 == 1)
				result = 8;
			if (b % 4 == 2)
				result = 4;
			if (b % 4 == 3)
				result = 2;
			if (b % 4 == 0)
				result = 6;
		}
		else if (a % 10 == 9)
		{
			if (b % 2 == 1)
				result = 9;
			if (b % 2 == 0)
				result = 1;
		}
		else if (a % 10 == 0)
			result = 10;

		printf("%d\n", result);
	}
}