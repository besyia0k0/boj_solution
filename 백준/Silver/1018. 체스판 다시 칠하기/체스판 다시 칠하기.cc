#include <iostream>

using namespace std;

char	chess[51][51];

int		check_chess(int x, int y);
void	fastio(void);

int main(void)
{
	int n, m, tmp, min = 64;
	
	fastio();
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> chess[i][j];
	for (int i = 0; i < n - 7; i++)
		for (int j = 0; j < m - 7; j++)
		{
			tmp = check_chess(i, j);
			if (tmp < min)
				min = tmp;
		}
	cout << min << "\n";
	return (0);
}

int	check_chess(int x, int y)
{
	int	wrong = 0;

	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((x + i) % 2 == 0)
			{
				if ((y + j) % 2 == 0) {
					if (chess[x + i][y + j] != 'W')
						wrong++;
				}
				else {
					if (chess[x + i][y + j] != 'B')
						wrong++;
				}
			}
			else
			{
				if ((y + j) % 2 == 0) {
					if (chess[x + i][y + j] != 'B')
						wrong++;
				}
				else {
					if (chess[x + i][y + j] != 'W')
						wrong++;
				}
			}
		}
	}
	return (wrong > 32 ? 64 - wrong : wrong);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}