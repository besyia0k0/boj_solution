#include <iostream>
#include <queue>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int box[101][101][101];
queue<pair<int, pair<int, int>>> q;
int m, n, h;
void bfs();

int main(void)
{
	int day = 0;

	fastio;
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
			{
				cin >> box[i][j][k];
				if (box[i][j][k] == 1)
					q.push({i, {j, k}});
			}
	bfs();
	for (int i = 0; i < h; i++)
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
			{
				if (box[i][j][k] == 0)
				{
					cout << "-1\n";
					return (0);
				}
				if (box[i][j][k] > day)
					day = box[i][j][k];
			}
	cout << day - 1 << "\n";
	return (0);
}

void bfs()
{
	int x_tmp, y_tmp, z_tmp;
	pair<int, pair<int, int>> dist[6] = {{1, {0, 0}}, {-1, {0, 0}}, {0, {1, 0}}, {0, {-1, 0}}, {0, {0, 1}}, {0, {0, -1}}};
	pair<int, pair<int, int>> elem;

	while (!q.empty())
	{
		elem = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			x_tmp = elem.first + dist[i].first;
			y_tmp = elem.second.first + dist[i].second.first;
			z_tmp = elem.second.second + dist[i].second.second;
			if (x_tmp >= 0 && x_tmp < h && y_tmp >= 0 && y_tmp < n && z_tmp >= 0 && z_tmp < m)
			{
				if (box[x_tmp][y_tmp][z_tmp] == 0)
				{
					box[x_tmp][y_tmp][z_tmp] = box[elem.first][elem.second.first][elem.second.second] + 1;
					q.push({x_tmp, {y_tmp, z_tmp}});
				}
			}
		}
	}
}