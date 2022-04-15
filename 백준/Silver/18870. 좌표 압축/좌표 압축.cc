#include <iostream>
#include <vector>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	vector<int> input, order;
	int n, tmp;

	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		input.push_back(tmp);
		order.push_back(tmp);
	}
	sort(order.begin(), order.end());
	order.erase(unique(order.begin(), order.end()), order.end());
	for (int i = 0; i < n; i++)
		cout << (lower_bound(order.begin(), order.end(), input[i]) - order.begin()) << " ";
	return (0);
}