#include <iostream>

using namespace std;

int factorial(int x);

int main(void)
{
	int	x, y;

	cin >> x >> y;
	cout << factorial(x) / (factorial(y) * factorial(x - y));
	return (0);
}

int factorial(int x)
{
	if (x == 1 || x == 0)
		return (1);
	return (factorial(x - 1) * x);
}