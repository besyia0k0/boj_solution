#include <iostream>
#include <vector>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

bool comp(pair<int, int> x, pair<int, int> y);

int main(void)
{
	int n, start, end, cnt = 1;
	vector<pair<int, int>> list;

	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> start >> end;
		list.push_back({start, end});
	}
	sort(list.begin(), list.end(), comp);
	end = list.front().second;
	for (int i = 1; i < n; i++)
	{
		if (list[i].first >= end)
		{
			end = list[i].second;
			cnt++;
		}
	}
	cout << cnt << "\n";
	return (0);
}

bool comp(pair<int, int> x, pair<int, int> y)
{
	if (x.second == y.second)
		return (x.first < y.first);
	return (x.second < y.second);
}