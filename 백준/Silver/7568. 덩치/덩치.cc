#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
	vector<pair<int, int>>	info;
	vector<int>	rank;
	int n, x, y;
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> x >> y;
		rank.push_back(1);
		info.push_back({ x, y });
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (info[j].first > info[i].first && info[j].second > info[i].second)
				rank[i]++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << rank[i] << " ";
	return (0);
}