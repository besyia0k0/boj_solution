#include <iostream>
#include <queue>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	int n, tmp;
	priority_queue<int> pq;

	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp == 0)
		{
			if (pq.empty())
				cout << "0\n";
			else
			{
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(tmp);
	}
	return (0);
}