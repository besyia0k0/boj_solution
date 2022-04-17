#include <iostream>
#include <set>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	multiset<pair<int, int>> m;
	int n, x;

	fastio;
	cin >> n;
	while (n--)
	{
		cin >> x;
		if (x)
			m.insert({(x > 0 ? x : -x), x});
		else
		{
			if (!m.empty())
			{
				cout << m.begin()->second << "\n";
				m.erase(m.begin());
			}
			else
				cout << "0\n";
		}
	}
	return (0);
}