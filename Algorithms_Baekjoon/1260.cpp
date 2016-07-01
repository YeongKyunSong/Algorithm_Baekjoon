#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <stdio.h>

using namespace std;

int N, M, V;
vector<vector<bool>> index;
vector<bool> vertex;

void dfs(int *V) {
	int v = *V;
	vertex[v] = false;
	for (int i = 1; i < N + 1; i++) {
		if (index[v][i] == true && vertex[i]==true) {
			printf("%d ", i);
			dfs(&i);
		}
	}
}

void bfs(int v) {


}

int main() {
	scanf("%d %d %d", &N, &M, &V);
	int a, b;

	index.assign(N+1, vector<bool>(N+1, false));
	vertex.assign(N + 1, true);
	

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		index[a][b] = true;
		index[b][a] = true;
	}

	printf("%d ", V);
	dfs(&V);

	vertex.assign(N + 1, true);
	printf("\n%d ", V);
	bfs(V);
	
	return 0;
}