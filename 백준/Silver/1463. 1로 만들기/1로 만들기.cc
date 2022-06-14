#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#define INF (1<<31)-2

using namespace std;

int arr[1000002];

int main() {
	int T = 0;
	scanf("%d", &T);

	fill(arr, arr + T + 1, INF);

	arr[1] = 0;

	for (int i = 1; i < T; i++) {
		if (i * 2 <= T)
			arr[i * 2] = min(arr[i * 2], arr[i] + 1);
		if (i * 3 <= T)
			arr[i * 3] = min(arr[i * 3], arr[i] + 1);
		if (i + 1 <= T)
			arr[i + 1] = min(arr[i + 1], arr[i] + 1);
	}

	printf("%d", arr[T]);

	return 0;
}