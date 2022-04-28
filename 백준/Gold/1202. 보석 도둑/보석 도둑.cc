#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	priority_queue<int> jewelry_pq;
	vector<pair<int, int>> jewelry;
	vector<pair<int, int>>::iterator it;
	vector<int> bag;
	int jewelry_num, bag_num, size, money;
	long long tot = 0;

    fastio;
	cin >> jewelry_num >> bag_num;
	for (int i = 0; i < jewelry_num; i++)
	{
		cin >> size >> money;
		jewelry.push_back({size, money});
	}
	sort(jewelry.begin(), jewelry.end());
	for (int i = 0; i < bag_num; i++)
	{
		cin >> size;
		bag.push_back(size);
	}
	sort(bag.begin(), bag.end());
	it = jewelry.begin();
	for (int i = 0; i < bag_num; i++)
	{
		for (; it != jewelry.end() && it->first <= bag[i]; it++)
			jewelry_pq.push(it->second);
		if (!jewelry_pq.empty())
		{
			tot += jewelry_pq.top();
			jewelry_pq.pop();
		}
	}
	cout << tot << "\n";
	return (0);
}