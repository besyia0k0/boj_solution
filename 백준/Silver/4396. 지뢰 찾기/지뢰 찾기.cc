#include <iostream>
#include <string>

using namespace std;

char	map[11][11];
char	opened[11][11];
char	ret[11][11];
int		n, boom;

void	fastio(void);
int		check(int i, int j);

int main(void)
{
	fastio();
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	for (int i = 0; i < n; i++)
	{
		cin >> opened[i];
		if (!boom)
		{
			for (int j = 0; j < n; j++)
				if (opened[i][j] == 'x' && map[i][j] == '*')
				{	boom = 1;	break;	}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n ; j++)
		{
			if (opened[i][j] == 'x')
			{
				if (boom && map[i][j] == '*')
					ret[i][j] = map[i][j];
				else
				 	ret[i][j] = check(i, j) + '0';
			}
			else if (boom)
				ret[i][j] = map[i][j];
			else
				ret[i][j] = '.';
		}
	}
	for (int i = 0; i < n; i++)
		cout << ret[i] <<'\n';
	return (0);
}

int	check(int i, int j)
{
	int	dir[8][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}, {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
	int	x, y, check = 0;

	for (int k = 0; k < 8; k++)
	{
		x = i + dir[k][0];
		y = j + dir[k][1];
		if (x >= 0 && y >= 0 && x < n && y < n)
		{
			if (map[x][y] == '*')
				check++;
		}
	}
	return (check);
}


void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}