#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;

int compare(const void *a, const void *b)
{
	if (*(char*)a > *(char*)b) return 1;
	else if (*(char*)a == *(char*)b) return 0;
	else return -1;
}

int main()
{
	int n = 0;

	cin >> n;

	int* tmp1 = new int[n];
	int* tmp2 = new int[n];
	int result = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> tmp1[i];
	}
	for (int i = 0; i < n; i++)
	{
		cin >> tmp2[i];
	}

	qsort((void*)tmp1, n, sizeof(int), compare);
	qsort((void*)tmp2, n, sizeof(int), compare);

	for (int i = 0; i < n; i++)
	{
		result += tmp1[i] * tmp2[n - i - 1];
	}

	cout << result;
}