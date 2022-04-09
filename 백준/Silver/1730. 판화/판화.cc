#include <iostream>
#include <string>
#include <utility>
#include <memory.h>

using namespace std;

char	map[11][11];
int		n, x, y;
void	fastio(void);
int		set_dir(char c);

int main(void)
{
	string	s;
	int		x_tmp, y_tmp;
	char	prev;

	fastio();
	prev = 0;
	cin >> n;
	cin >> s;
	memset(map, '.', sizeof(map));
	for (int i = 0; i < n; i++)
		map[i][n] = 0;
	for (int i = 0; i < s.length();i++)
	{
		x_tmp = x;
		y_tmp = y;
		if (!set_dir(s[i]))
			continue;
		switch (s[i])
		{
			case 'D':
			case 'U':
				if (prev == 0 || prev == 'D' || prev == 'U')
				{
					if (map[x_tmp][y_tmp] != '+')
					{
						if (map[x_tmp][y_tmp] == '-')
							map[x_tmp][y_tmp] = '+';
						else
							map[x_tmp][y_tmp] = '|';
					}
					if (map[x][y] != '+')
					{
						if (map[x][y] == '-')
							map[x][y] = '+';
						else
							map[x][y] = '|';
					}
				}
				else
				{
					map[x_tmp][y_tmp] = '+';
					if (map[x][y] != '+')
					{
						if (map[x][y] == '-')
							map[x][y] = '+';
						else
							map[x][y] = '|';
					}
				}
				break;
			case 'R':
			case 'L':
				if (prev == 0 || prev == 'R' || prev == 'L')
				{
					if (map[x_tmp][y_tmp] != '+')
					{
						if (map[x_tmp][y_tmp] == '|')
							map[x_tmp][y_tmp] = '+';
						else
							map[x_tmp][y_tmp] = '-';
					}
					if (map[x][y] != '+')
					{
						if (map[x][y] == '|')
							map[x][y] = '+';
						else
							map[x][y] = '-';
					}
				}
				else
				{
					map[x_tmp][y_tmp] = '+';
					if (map[x][y] != '+')
					{
						if (map[x][y] == '|')
							map[x][y] = '+';
						else
							map[x][y] = '-';
					}
				}
				break;
		}
		prev = s[i];
	}
	for (int i = 0; i < n; i++)
		cout << map[i] << "\n";
	return (0);
}

int	set_dir(char c)
{
	pair<int, int>	dir[4] = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
	int tmp;
	switch (c)
	{
		case 'D':
			tmp = 0;	break;
		case 'U':
			tmp = 1;	break;
		case 'R':
			tmp = 2;	break;
		case 'L':
			tmp = 3;	break;
	}
	if (x + dir[tmp].first >= 0 && x + dir[tmp].first < n && y + dir[tmp].second >= 0 && y + dir[tmp].second < n)
	{
		x += dir[tmp].first;
		y += dir[tmp].second;
		return (1);
	}
	return (0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}