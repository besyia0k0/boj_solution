#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void	fastio(void);
bool	comp(pair<int, int> x, pair<int, int>y);
int main(void)
{
	vector<pair<int, int>>	v;
	int n, x, y;
	
	fastio();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		v.push_back({ x, y });
	}
	sort(v.begin(), v.end(), comp);
	for (int i = 0; i < n; i++)
		cout << v[i].first << " " << v[i].second << "\n";
	return (0);
}

bool	comp(pair<int, int> x, pair<int, int>y)
{
	if (x.second == y.second)
		return (x.first < y.first);
	return (x.second < y.second);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}