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
	char tmp[11] = { 0 };
	char temp[11] = { 0 };
	char result[11] = { 0 };
	int n = 0;

	cin >> tmp;

	while (tmp[++n]);

	qsort((void*)tmp, n, sizeof(char), compare);
	for (int i = n - 1; i >= 0; i--)
	{
		cout << tmp[i];
	}
}