#include <iostream>
#include <queue>
#include <vector>
#include <memory.h>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int check(vector<pair<int, int>> v, int x);

int main(void)
{
	queue<pair<int, int>> q;
	vector<pair<int, int>> snake, ladder;
	int visited[101];
	int ladder_num, snake_num, a, b, cur, times;

	fastio;
	cin >> ladder_num >> snake_num;
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < ladder_num; i++)
	{
		cin >> a >> b;
		ladder.push_back({a, b});
	}
	for (int i = 0; i < snake_num; i++)
	{
		cin >> a >> b;
		snake.push_back({a, b});
	}
	q.push({1, 0});
	while (!q.empty())
	{
		cur = q.front().first;
		times = q.front().second;
		q.pop();
		for (int i = 1; i <= 6; i++)
		{
			if (cur + i == 100)
			{
				cout << times + 1 << "\n";
				return (0);
			}
			if (cur + i < 100 && !visited[cur + i])
			{
				a = check(ladder, cur + i);
				b = check(snake, cur + i);
				if (!a && !b)
				{
					visited[cur + i] = 1;
					q.push({cur + i, times + 1});
				}
				if (a && !visited[a])
				{
					visited[a] = 1;
					q.push({a, times + 1});
				}
				if (b && !visited[b])
				{
					visited[b] = 1;
					q.push({b, times + 1});
				}
			}
		}
	}
	return (0);
}

int check(vector<pair<int, int>> v, int x)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i].first == x)
			return (v[i].second);
	}
	return (0);
}