#include <iostream>
#include <string>
using namespace std;

void	fastio(void);
int	apt[15][15];

int main(void)
{
	int n, x, y;
	for (int i = 1; i < 15; i++)
		apt[0][i] = i;
	for (int i = 1; i < 15; i++)
	{
		for (int j = 1; j < 15; j++)
		{
			for (int k = 1; k <= j; k++)
			{
				apt[i][j] += apt[i - 1][k];
			}
		}
	}
	cin >> n;
	while (n--)
	{
		cin >> x >> y;
		cout << apt[x][y] << "\n";
	}
	return (0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}