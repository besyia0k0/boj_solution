#include <iostream>
#include <memory.h>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int paper[501][501];
short visited[20][20];
int n, m, a, b, max_num = 0;
void dfs_check(int x, int y, int times, int size);
void check(int x, int y);

int main(void)
{
	fastio;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> paper[i][j];
	for (; a < n; a++)
		for (b = 0; b < m; b++)
			dfs_check(a, b, 1, paper[a][b]);
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

void dfs_check(int x, int y, int times, int size)
{
	pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	int tmp_x, tmp_y;

	if (times == 4)
	{
		if (max_num < size)
			max_num = size;
		return;
	}
	if (times == 1)
	{
		memset(visited, 0, sizeof(visited));
		visited[9][9] = 1;
	}
	for (int i = 0; i < 4; i++)
	{
		tmp_x = x + dir[i].first;
		tmp_y = y + dir[i].second;
		if (tmp_x >= 0 && tmp_y >= 0 && tmp_x < n && tmp_y < m && !visited[9 + (tmp_x - a)][9 + (tmp_y - b)])
		{
			visited[9 + (tmp_x - a)][9 + (tmp_y - b)] = 1;
			dfs_check(tmp_x, tmp_y, times + 1, size + paper[tmp_x][tmp_y]);
			visited[9 + (tmp_x - a)][9 + (tmp_y - b)] = 0;
		}
	}
}