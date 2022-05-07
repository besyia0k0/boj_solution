#include <iostream>
#include <string>
#include <queue>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

bool map[101][101];
int height, width;
void bfs(int init_x, int init_y);

int main(void)
{
	int t_case, check = 0;
	string s;

	fastio;
	cin >> t_case;
	while (t_case--)
	{
		cin >> height >> width;
		check = 0;
		for (int i = 0; i < height; i++)
		{
			cin >> s;
			for (int j = 0; j < width; j++)
				if (s[j] == '#')
					map[i][j] = 1;
		}
		for (int i = 0; i < height; i++)
			for (int j = 0; j < width; j++)
				if (map[i][j])
				{
					bfs(i, j);
					check++;
				}
		cout << check << "\n";
	}
	return (0);
}

void bfs(int init_x, int init_y)
{
	queue<pair<int, int>> q;
	pair<int, int> dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
	pair<int, int> node;
	int tmp_x, tmp_y;

	q.push({init_x, init_y});
	map[init_x][init_y] = false;
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			tmp_x = node.first + dir[i].first;
			tmp_y = node.second + dir[i].second;
			if (tmp_x >= 0 && tmp_y >= 0 && tmp_x < height && tmp_y < width && map[tmp_x][tmp_y])
			{
				map[tmp_x][tmp_y] = false;
				q.push({tmp_x, tmp_y});
			}
		}
	}
}