#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int bfs(int start, int target);

int main(void)
{
	int start, target;

	cin >> start >> target;
	cout << bfs(start, target) << "\n";
	return (0);
}

int bfs(int start, int target)
{
	queue<pair<int, int>> q;
	int visited[100001];
	pair<int, int> node;
	int min_time = -1, count = 0;

	fill(visited, visited + 100001, 200000);
	visited[start] = 0;
	q.push({start, 0});
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		if (node.first + 1 <= 100000 && visited[node.first + 1] > node.second + 1)
		{
			visited[node.first + 1] = node.second + 1;
			q.push({node.first + 1, node.second + 1});
		}
		if (node.first - 1 >= 0 && visited[node.first - 1] > node.second + 1)
		{
			visited[node.first - 1] = node.second + 1;
			q.push({node.first - 1, node.second + 1});
		}
		if (node.first * 2 <= 100000 && visited[node.first * 2] > node.second)
		{
			visited[node.first * 2] = node.second;
			q.push({node.first * 2, node.second});
		}
	}
	return (visited[target]);
}