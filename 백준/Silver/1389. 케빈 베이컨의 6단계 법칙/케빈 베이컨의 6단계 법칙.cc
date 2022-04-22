#include <iostream>
#include <queue>
#include <memory.h>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

vector<int> g[101];
int node_num;
int bfs(int x);

int main(void)
{
	int line_num, x, y, min = 5001, min_ele, tmp;

	fastio;
	cin >> node_num >> line_num;
	for (int i = 0; i < line_num; i++)
	{
		cin >> x >> y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for (int i = 1; i <= node_num; i++)
	{
		tmp = bfs(i);
		if (tmp < min)
		{
			min = tmp;
			min_ele = i;
		}
	}
	cout << min_ele << "\n";
	return (0);
}

int bfs(int x)
{
	queue<int> q;
	int visited[101];
	int node, depth = 1, tot = 0;

	memset(visited, 0, sizeof(visited));
	q.push(x);
	visited[x] = 1;
	q.push(0);
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		if (!node && !q.empty())
		{
			depth++;
			q.push(node);
			continue;
		}
		for (int i = 0; i < g[node].size(); i++)
		{
			if (!visited[g[node][i]])
			{
				q.push(g[node][i]);
				visited[g[node][i]] = depth;
				tot += depth;
			}
		}
	}
	return (tot);
}