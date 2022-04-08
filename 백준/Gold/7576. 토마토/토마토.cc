#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int		box[1001][1001];
queue<pair<int, int>> q;
int m, n;
void	fastio(void);
void	bfs();

int main(void)
{
	int	day = 0;

	fastio();
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> box[i][j];
			if (box[i][j] == 1)
				q.push({ i, j });
		}
	}
	bfs();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (box[i][j] == 0)
			{
				cout << "-1\n";
				return (0);
			}
			if (box[i][j] > day)
				day = box[i][j];
		}
	}
	cout << day - 1 << "\n";
	return (0);
}

void    bfs()
{
	int x_tmp, y_tmp;
	pair<int, int>	dist[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
	pair<int, int>	elem;
	
	while (!q.empty())
	{
		elem = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			x_tmp = elem.first + dist[i].first;
			y_tmp = elem.second + dist[i].second;
			if (x_tmp >= 0 && x_tmp < n && y_tmp >= 0 && y_tmp < m)
			{
				if (box[x_tmp][y_tmp] == 0)
				{
					box[x_tmp][y_tmp] = box[elem.first][elem.second] + 1;
					q.push({ x_tmp, y_tmp });
				}
			}
		}
	}
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}