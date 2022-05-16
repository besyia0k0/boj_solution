#include <iostream>
#include <vector>
#include <algorithm>
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	vector<int> lst;
	long long result = 0, minus = 0, m_tmp = 0;
	int tot, choose, tmp;

    fastio;
	cin >> tot >> choose;
	for (int i = 0; i < tot; i++)
	{
		cin >> tmp;
		lst.push_back(tmp);
		result += tmp;
	}
	sort(lst.begin(), lst.end());
	result *= choose;
	for (int i = 0; i < choose; i++)
	{
		minus += m_tmp + lst[i];
		m_tmp += lst[i];
	}
	cout << result - minus << "\n";
	return (0);
}