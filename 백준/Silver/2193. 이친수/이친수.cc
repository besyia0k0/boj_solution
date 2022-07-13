#include <iostream>
using namespace std;

long long zero[92], one[92];

int main(void)
{
	int N;

	cin >> N;
	if (N == 1) {
		cout << 1;
		return 0;
	}
	zero[2] = 1;
	one[2] = 0;
	for (int i = 3; i <= 90; i++) {
		zero[i] = zero[i - 1] + one[i - 1];
		one[i] = zero[i - 1];
	}
	cout << zero[N] + one[N] << "\n";
	return 0;
}