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
	vector<int> comb;
	int n, m;

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		if (i <= m)
			comb.push_back(1);
		else
			comb.push_back(0);
	}
	do
	{
		for (int i = 1; i <= n; i++)
		{
			if (comb[i - 1])
				cout << i << " ";
		}
		cout << "\n";
	} while (prev_permutation(comb.begin(), comb.end()));
	return (0);
}