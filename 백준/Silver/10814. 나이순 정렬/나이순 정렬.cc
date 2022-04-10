#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;
void	fastio(void);
bool    comp(pair<int, string> x, pair<int, string> y);

int main(void)
{
	vector<pair<int, string>>	list;
	string s;
	int n, age;

	fastio();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> age >> s;
		list.push_back({age, s});
	}
	stable_sort(list.begin(), list.end(), comp);
	for (int i = 0; i < n; i++)
		cout << list[i].first << " " << list[i].second <<"\n";
	return (0);
}

bool comp(pair<int, string> x, pair<int, string> y)
{
	return (x.first < y.first);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}