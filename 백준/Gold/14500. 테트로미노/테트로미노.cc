#include <iostream>
#include <memory.h>
#include <deque>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int paper[501][501];
short visited[20][20];
deque<pair<int, int>> pos;
int n, m, max_num = 0;
void bfs_check(int x, int y, int times, int size);
void check(int x, int y);
bool comp(pair<int, pair<int, int>> x, pair<int, pair<int, int>> y);

int main(void)
{
	fastio;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			bfs_check(i, j, 0, 0);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			check(i, j);
	cout << max_num << "\n";
	return (0);
}

void check(int x, int y)
{
	int tmp_max, tmp = 0;

	if (x > 0 && y > 0 && x < n - 1 && y < m - 1)
	{
		tmp = paper[x][y] + paper[x - 1][y] + paper[x + 1][y];
		tmp += (paper[x][y - 1] > paper[x][y + 1] ? paper[x][y - 1] : paper[x][y + 1]);
		tmp_max = tmp;
		tmp = paper[x][y] + paper[x][y - 1] + paper[x][y + 1];
		tmp += (paper[x + 1][y] > paper[x - 1][y] ? paper[x + 1][y] : paper[x - 1][y]);
		tmp_max = (tmp_max > tmp ? tmp_max : tmp);
		max_num = (tmp_max > max_num ? tmp_max : max_num);
		return;
	}
	if (y > 0 && y < m - 1)
	{
		if (x == n - 1)
			tmp = paper[x][y] + paper[x][y - 1] + paper[x][y + 1] + paper[x - 1][y];
		else if (x == 0)
			tmp = paper[x][y] + paper[x][y - 1] + paper[x][y + 1] + paper[x + 1][y];
	}
	else if (x > 0 && x < n - 1)
	{
		if (y == m - 1)
			tmp = paper[x][y] + paper[x - 1][y] + paper[x + 1][y] + paper[x][y - 1];
		else if (y == 0)
			tmp = paper[x][y] + paper[x - 1][y] + paper[x + 1][y] + paper[x][y + 1];
	}
	max_num = (tmp > max_num ? tmp : max_num);
}

void bfs_check(int x, int y, int times, int size)
{
	pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	pair<int, int> node;
	int tmp_x, tmp_y;

	if (times == 4)
	{
		if (max_num < size)
			max_num = size;
		return;
	}
	if (times == 0)
	{
		memset(visited, 0, sizeof(visited));
		visited[9][9] = 1;
		pos.push_back({x, y});
		bfs_check(x, y, 1, paper[x][y]);
		return;
	}
	node = pos.back();
	pos.pop_back();
	for (int i = 0; i < 4; i++)
	{
		tmp_x = node.first + dir[i].first;
		tmp_y = node.second + dir[i].second;
		if (tmp_x >= 0 && tmp_y >= 0 && tmp_x < n && tmp_y < m && !visited[9 + (tmp_x - x)][9 + (tmp_y - y)])
		{
			pos.push_back({tmp_x, tmp_y});
			visited[9 + (tmp_x - x)][9 + (tmp_y - y)] = 1;
			bfs_check(x, y, times + 1, size + paper[tmp_x][tmp_y]);
			visited[9 + (tmp_x - x)][9 + (tmp_y - y)] = 0;
		}
	}
}