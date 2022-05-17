#include <iostream>
#include <queue>
#include <algorithm>
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

char map[1001][1001];
bool visited[1001][1001][2];
int n, m;
int bfs(void);

int main(void)
{
    fastio;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> map[i];
	if (n == 1 && m == 1 && map[0][0]=='0')
		cout << "1";
	else
		cout << bfs();
	return (0);
}

int bfs(void)
{
	queue<pair<pair<int, int>, pair<bool, int>>> q;
	pair<int, int> cur, tmp, dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	bool broke;
	int length, x, y;

	q.push({{0, 0}, {false, 1}});
	visited[0][0][0] = true;
	while (!q.empty())
	{
		cur = q.front().first;
		broke = q.front().second.first;
		length = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			x = cur.first + dir[i].first;
			y = cur.second + dir[i].second;
			if (x == n - 1 && y == m - 1)
				return (length + 1);
			if (x >= 0 && y >= 0 && x < n && y < m && !visited[x][y][broke])
			{
				if (map[x][y] == '0')
				{
					visited[x][y][broke] = true;
					q.push({{x, y}, {broke, length + 1}});
				}
				else if (!broke)
				{
					visited[x][y][1] = true;
					q.push({{x, y}, {true, length + 1}});
				}
			}
		}
	}
	return (-1);
}