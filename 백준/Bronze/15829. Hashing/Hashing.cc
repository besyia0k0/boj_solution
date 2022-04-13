#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	int n;
	long long ret = 0;
	string s;

	cin >> n >> s;
	for (int i = n - 1; i >= 0; i--)
	{
		ret += s[i] - 'a' + 1;
		ret %= 1234567891;
		if (i) {
			ret *= 31;
			ret %= 1234567891;
		}
	}
	cout << ret << "\n";
	return (0);
}