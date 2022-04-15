#include <iostream>
#include <set>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	int n, k, num;
	char flag;

	cin >> n;
	while (n--)
	{
		multiset<int> pq;

		cin >> k;
		while (k--)
		{
			cin >> flag >> num;
			if (flag == 'I')
				pq.insert(num);
			else
			{
				if (!pq.empty())
				{
					if (num > 0)
					{
						auto it = pq.end();
						pq.erase(--it, pq.end());
					}
					else
					{
						auto it = pq.begin();
						pq.erase(pq.begin(), ++it);
					}
				}
			}
		}
		if (pq.empty())
			cout << "EMPTY\n";
		else
			cout << *pq.rbegin() << " " << *pq.begin() << "\n";
	}
	return (0);
}