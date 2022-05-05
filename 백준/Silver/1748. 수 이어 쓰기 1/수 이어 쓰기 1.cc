//BOJ  No. 1748
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int N = 0;
	scanf("%d", &N);
	int ten = 10;
	int numbers = 1;
	unsigned long long int answer = 0;

	while (1) {
		for (int i = 1; i < ten - (ten / 10 - 1); i++) {
			answer += (unsigned long long) numbers;
			N--;
			if (N == 0)
				break;
		}
		if (N == 0)
			break;
		ten *= 10;
		numbers++;
	}
	printf("%llu", answer);
	
	return 0;
}