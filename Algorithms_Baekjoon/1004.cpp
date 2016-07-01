#include<stdio.h>
#include<math.h>

int main()
{
	int i = 0;
	int T = 0;
	scanf("%d", &T);

	for (i = 0; i < T; i++)
	{
		int x1, y1, x2, y2;
		int n = 0;
		int cx, cy, r;
		int j = 0;
		int result = 0;

		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		scanf("%d", &n);

		for (j = 0; j < n; j++)
		{
			scanf("%d%d%d", &cx, &cy, &r);

			if ((((x1 - cx)*(x1 - cx) + (y1 - cy)*(y1 - cy) <= r*r) && ((x2 - cx)*(x2 - cx) + (y2 - cy)*(y2 - cy) >= r*r)) || (((x1 - cx)*(x1 - cx) + (y1 - cy)*(y1 - cy) >= r*r) && ((x2 - cx)*(x2 - cx) + (y2 - cy)*(y2 - cy) <= r*r)) || ((x2 - cx)*(x2 - cx) + (y2 - cy)*(y2 - cy) == r*r) || ((x1 - cx)*(x1 - cx) + (y1 - cy)*(y1 - cy) == r*r))
			{
				result++;
			}
		}
		printf("%d\n", result);
	}
}