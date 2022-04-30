#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

vector<pair<int, int>> tree[100001];
bool visited[100001];
pair<int, int> bfs(int start);

int main(void)
{
	int node, parent, child, weight;
	pair<int, int> max_node;

	cin >> node;
	for (int i = 0; i < node; i++)
	{
		cin >> parent;
		while (true)
		{
			cin >> child;
			if (child == -1)
				break;
			cin >> weight;
			tree[parent].push_back({child, weight});
		}
	}
	max_node = bfs(1);
	memset(visited, 0, sizeof(visited));
	cout << bfs(max_node.first).second << "\n";
	return (0);
}

pair<int, int> bfs(int start)
{
	queue<pair<int, int>> q;
	int node, weight, max_node = 0, max_weight = 0;

	q.push({start, 0});
	visited[start] = 1;
	while (!q.empty())
	{
		node = q.front().first;
		weight = q.front().second;
		if (weight > max_weight)
		{
			max_weight = weight;
			max_node = node;
		}
		q.pop();
		for (auto i : tree[node])
		{
			if (!visited[i.first])
			{
				q.push({i.first, weight + i.second});
				visited[i.first] = true;
			}
		}
	}
	return (make_pair(max_node, max_weight));
}