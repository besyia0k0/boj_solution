#include <iostream>
#include <set>
#include <queue>
#include <limits.h>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	set<int> visited;
	queue<int> q;
	int a, b, tmp, node, depth = 1;

	cin >> a >> b;
	q.push(a);
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
		if (node > 0 && node <= INT_MAX / 10)
		{
			tmp = node * 10 + 1;
			if (tmp == b)
			{
				cout << depth + 1 << "\n";
				return (0);
			}
			if (tmp <= b && visited.insert(tmp).second)
				q.push(tmp);
		}
		if (node > 0 && node <= INT_MAX / 2)
		{
			tmp = node * 2;
			if (tmp == b)
			{
				cout << depth + 1 << "\n";
				return (0);
			}
			if (tmp <= b && visited.insert(tmp).second)
				q.push(tmp);
		}
	}
	cout << "-1\n";
	return (0);
}