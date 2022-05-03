#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

short map[9][9];
queue<pair<int, int>> q;
bool visited[9][9];
int n, m, init_area, max_area;

void bfs(queue<pair<int, int>> q_copy);
void recur(int count);

int main(void)
{
    fastio;
	cin >> n >> m;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				q.push({i, j});
				visited[i][j] = true;
			}
			else if (map[i][j] == 0)
				init_area++;
			else
				visited[i][j] = true;
		}
	recur(0);
	cout << max_area << "\n";
	return (0);
}

void recur(int count)
{
	if (count == 3)
	{
		bfs(q);
		return;
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 0)
			{
				map[i][j] = 1;
				init_area--;
				recur(count + 1);
				map[i][j] = 0;
				init_area++;
			}
}

void bfs(queue<pair<int, int>> q_copy)
{
	pair<int, int> node;
	pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	short map_copy[9][9];
	bool visited_copy[9][9];
	int x, y, tmp_area = init_area;

	copy(&map[0][0], &map[0][0] + 81, &map_copy[0][0]);
	copy(&visited[0][0], &visited[0][0] + 81, &visited_copy[0][0]);
	while (!q_copy.empty())
	{
		node = q_copy.front();
		q_copy.pop();
		for (int i = 0; i < 4; i++)
		{
			x = node.first + dir[i].first;
			y = node.second + dir[i].second;
			if (x >= 0 && y >= 0 && x < n && y < m && !visited_copy[x][y] && map_copy[x][y] == 0)
			{
				visited_copy[x][y] = true;
				map_copy[x][y] = 2;
				tmp_area--;
				q_copy.push({x, y});
			}
		}
	}
	if (max_area < tmp_area)
		max_area = tmp_area;
}