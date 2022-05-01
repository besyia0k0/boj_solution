#include <iostream>
#include <vector>
#include <queue>
#include <memory.h>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

pair<int, int> bfs(int start, int target);

int main(void)
{
	int start, target;
	pair<int, int> result;

	cin >> start >> target;
	result = bfs(start, target);
	cout << result.first << "\n"
			 << result.second << "\n";
	return (0);
}

pair<int, int> bfs(int start, int target)
{
	queue<pair<int, int>> q;
	bool visited[100001];
	pair<int, int> node;
	int min_time = -1, count = 0;

	memset(visited, 0, sizeof(visited));
	q.push({start, 0});
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		visited[node.first] = true;
		if (min_time != -1 && node.second > min_time)
			break;
		if (node.first == target)
		{
			if (min_time == -1)
			{
				min_time = node.second;
				count++;
			}
			else
				count++;
		}
		if (node.first + 1 <= 100000 && !visited[node.first + 1])
			q.push({node.first + 1, node.second + 1});
		if (node.first - 1 >= 0 && !visited[node.first - 1])
			q.push({node.first - 1, node.second + 1});
		if (node.first * 2 <= 100000 && !visited[node.first * 2])
			q.push({node.first * 2, node.second + 1});
	}
	return (make_pair(min_time, count));
}