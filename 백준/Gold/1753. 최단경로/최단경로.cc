#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

vector<pair<int, int>> graph[20001];
vector<int> min_dist;
void dijkstra(int start, int node);

int main(void)
{
	int node, line, start, x, y, weight;

    fastio;
	cin >> node >> line >> start;
	min_dist.resize(node + 1, 10000000);
	for (int i = 0; i < line; i++)
	{
		cin >> x >> y >> weight;
		graph[x].push_back({y, weight});
	}
	dijkstra(start, node);
	for (int i = 1; i < min_dist.size(); i++)
	{
		if (min_dist[i] == 10000000)
			cout << "INF\n";
		else
			cout << min_dist[i] << "\n";
	}
	return (0);
}

void dijkstra(int start, int node)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	int weight, n;

	min_dist[start] = 0;
	pq.emplace(0, start);
	while (!pq.empty())
	{
		weight = pq.top().first;
		n = pq.top().second;
		pq.pop();
		if (min_dist[n] != weight)
			continue;
		for (auto i : graph[n])
		{
			if (min_dist[i.first] > weight + i.second)
			{
				min_dist[i.first] = weight + i.second;
				pq.emplace(weight + i.second, i.first);
			}
		}
	}
}