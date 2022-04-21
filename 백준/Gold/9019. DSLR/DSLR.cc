#include <iostream>
#include <queue>
#include <memory.h>
#include <string>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

string bfs(int cur, int target);
bool visited[10001];

int main(void)
{
	int t, cur, target;

	fastio;
	cin >> t;
	while (t--)
	{
		cin >> cur >> target;
		cout << bfs(cur, target) << "\n";
	}
	return (0);
}

string bfs(int cur, int target)
{
	queue<pair<int, string>> q;
	pair<int, string> node;
	int tmp;

	memset(visited, 0, sizeof(visited));
	visited[cur] = true;
	q.push({cur, ""});
	while (!q.empty())
	{
		node = q.front();
		q.pop();
		tmp = (node.first * 2) % 10000;
		if (!visited[tmp])
		{
			if (tmp == target)
				return (node.second + "D");
			q.push({tmp, node.second + "D"});
			visited[tmp] = true;
		}
		tmp = (node.first > 0 ? node.first - 1 : 9999);
		if (!visited[tmp])
		{
			if (tmp == target)
				return (node.second + "S");
			q.push({tmp, node.second + "S"});
			visited[tmp] = true;
		}
		tmp = (node.first % 1000) * 10 + node.first / 1000;
		if (!visited[tmp])
		{
			if (tmp == target)
				return (node.second + "L");
			q.push({tmp, node.second + "L"});
			visited[tmp] = true;
		}
		tmp = (node.first / 10) + (node.first % 10) * 1000;
		if (!visited[tmp])
		{
			if (tmp == target)
				return (node.second + "R");
			q.push({tmp, node.second + "R"});
			visited[tmp] = true;
		}
	}
	return ("");
}