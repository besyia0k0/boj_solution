#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

short	visited[100001];
void	fastio(void);
int		bfs(int x, int ans);

int main(void)
{
	int n, k;

	cin >> n >> k;
	cout << bfs(n, k);
	return (0);
}

int    bfs(int x, int ans)
{
	int tmp, dist;
	queue<pair<int, int>> q;

	q.push({ x, 0 });
	visited[x] = 1;
	while (!q.empty())
	{
		tmp = q.front().first;
		dist = q.front().second;
		q.pop();
		if (tmp < 100000)
		{
			if (visited[tmp + 1] == 0)
			{
				if (tmp + 1 == ans)
					return (dist + 1);
				q.push({ tmp + 1, dist + 1 });
				visited[tmp + 1] = 1;
			}
		}
		if (tmp > 0)
		{
			if (visited[tmp - 1] == 0)
			{
				if (tmp - 1 == ans)
					return (dist + 1);
				q.push({ tmp - 1, dist + 1 });
				visited[tmp - 1] = 1;
			}
		}
		if (2 * tmp <= 100000)
		{
			if (visited[tmp * 2] == 0)
			{
				if (tmp * 2 == ans)
					return (dist + 1);
				q.push({ tmp * 2, dist + 1 });
				visited[tmp * 2] = 1;
			}
		}
	}
	return (0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}