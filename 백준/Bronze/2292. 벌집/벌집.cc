#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int n, minus = 6, tmp = 2;

	cin >> n;
	if (n == 1)
	{
		cout << "1\n";
		return (0);
	}
	n--;
	while (n > minus)
	{
		n -= minus;
		minus += 6;
		tmp++;
	}
	cout << tmp << "\n";
	return (0);
}