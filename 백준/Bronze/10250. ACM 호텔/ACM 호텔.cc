#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void	fastio(void);

int main(void)
{
	int	height, width, n, m, ret;

	fastio();
	cin >> m;
	while (m--)
	{
		cin >> height >> width >> n;
		ret = ((--n) % height) + 1;
		ret *= 100;
		ret += (n / height) + 1;
		cout << ret << "\n";
	}
	return (0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}