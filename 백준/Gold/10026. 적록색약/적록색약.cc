#include <iostream>
#include <string>
#include <memory.h>
#include <queue>
#include <utility>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

char pic[101][101];
short visited[101][101];
int line, red, green, blue, x_rg;
void bfs(int x, int y, int flag);

int main(void)
{
	fastio;
	cin >> line;
	for (int i = 0; i < line; i++)
		cin >> pic[i];
	for (int i = 0; i < line; i++)
		for (int j = 0; j < line; j++)
			if (!visited[i][j])
				bfs(i, j, 0);
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < line; i++)
		for (int j = 0; j < line; j++)
			if (!visited[i][j])
				bfs(i, j, 1);
	cout << red + green + blue << " " << x_rg + blue << "\n";
	return (0);
}

void bfs(int x, int y, int flag)
{
	queue<pair<int, int>> q;
	pair<int, int> dir[4] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	pair<int, int> node;
	int x_tmp, y_tmp;
	char c = pic[x][y];

	if (!flag)
	{
		if (c == 'R')
			red++;
		else if (c == 'G')
			green++;
		else
			blue++;
	}
	else
	{
		if (c == 'R' || c == 'G')
			x_rg++;
		else
			return;
	}
	q.push({x, y});
	visited[x][y] = 1;
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			x_tmp = node.first + dir[i].first;
			y_tmp = node.second + dir[i].second;
			if (x_tmp >= 0 && y_tmp >= 0 && x_tmp < line && y_tmp < line && !visited[x_tmp][y_tmp] && ((!flag && pic[x_tmp][y_tmp] == c) || (flag && pic[x_tmp][y_tmp] != 'B')))
			{
				visited[x_tmp][y_tmp] = 1;
				q.push({x_tmp, y_tmp});
			}
		}
	}
}
