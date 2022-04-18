#include <iostream>
#include <memory.h>
#include <vector>
#include <queue>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int space[21][21];
int space_size, shark_size = 2, shark_size_tmp, s_time;
pair<int, int> shark_locate;
bool bfs(void);

int main(void)
{
	fastio;
	cin >> space_size;
	for (int i = 0; i < space_size; i++)
		for (int j = 0; j < space_size; j++)
		{
			cin >> space[i][j];
			if (space[i][j] == 9)
			{
				shark_locate = {i, j};
				space[i][j] = 0;
			}
		}
	while (bfs());
	cout << s_time << "\n";
	return (0);
}

bool bfs(void)
{
	queue<pair<int, int>> q;
	pair<int, int> dir[4] = {{-1, 0}, {0, -1}, {0, 1}, {1, 0}};
	pair<int, int> node, result = {-1, -1};
	int visited[21][21];
	int x_tmp, y_tmp, depth = 0;

	memset(visited, 0, sizeof(int) * 21 * 21);
	q.push(shark_locate);
	q.push({-1, -1});
	visited[shark_locate.first][shark_locate.second] = 1;
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		if (node.first == -1)
		{
			if (result != node)
				break;
			if (!q.empty())
			{
				depth++;
				q.push(node);
				continue;
			}
		}
		if (space[node.first][node.second] != 0 && space[node.first][node.second] < shark_size)
		{
			if (result.first == -1)
				result = node;
			else if (result.first > node.first)
				result = node;
			else if (result.first == node.first && result.second > node.second)
				result = node;
		}
		for (int i = 0; i < 4; i++)
		{
			x_tmp = node.first + dir[i].first;
			y_tmp = node.second + dir[i].second;
			if (x_tmp >= 0 && x_tmp < space_size && y_tmp >= 0 && y_tmp < space_size && !visited[x_tmp][y_tmp] && space[x_tmp][y_tmp] <= shark_size)
			{
				visited[x_tmp][y_tmp] = 1;
				q.push({x_tmp, y_tmp});
			}
		}
	}
	if (result.first != -1)
	{
		shark_locate = result;
		space[result.first][result.second] = 0;
		shark_size_tmp++;
		s_time += depth;
		if (shark_size_tmp >= shark_size)
		{
			shark_size++;
			shark_size_tmp = 0;
		}
		return (true);
	}
	return (false);
}