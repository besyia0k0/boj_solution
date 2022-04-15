#include <iostream>
#include <vector>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

vector<int> graph[1001];
short visited[1001];
vector<int> stk;

void dfs(void);

int main(void)
{
	int node, line, x, y, ret = 0;

	cin >> node >> line;
	for (int i = 0; i < line; i++)
	{
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	for (int i = 1; i <= node; i++)
	{
		if (visited[i] == 0)
		{
			stk.push_back(i);
			visited[i] = 1;
			dfs();
			ret++;
		}
	}
	cout << ret << "\n";
	return (0);
}

void dfs(void)
{
	int tmp;

	while (!stk.empty())
	{
		tmp = stk.back();
		stk.pop_back();
		for (int i = 0; i < graph[tmp].size(); i++)
		{
			if (visited[graph[tmp][i]] == 0)
			{
				stk.push_back(graph[tmp][i]);
				visited[graph[tmp][i]] = 1;
			}
		}
	}
}