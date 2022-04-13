#include <iostream>
using namespace std;

void	fastio(void);
short	map[1000001];
int main(void)
{
	int n, m;

	fastio();
	map[1] = 1;
	for (int i = 2; i <= 500000; i++)
	{
		if (!map[i])
		{
			for (int j = i * 2; j <= 1000000; j += i)
				map[j] = 1;
		}
	}
	cin >> n >> m;
	for (int i = n; i <= m; i++)
	{
		if (!map[i])
			cout << i << "\n";
	}
	return (0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}