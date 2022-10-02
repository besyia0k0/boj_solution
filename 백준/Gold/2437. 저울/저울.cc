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
	int	n, k;
	long result = 1;
	vector<int> v;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> k;
		v.push_back(k);
	}
	sort(v.begin(), v.end());
	if (v[0] > 1)
	{
		cout << 1 << '\n';
		return (0);
	}
	for (int i = 0; i < n; i++)
	{
		if (v[i] <= result)
			result += v[i];
		else
			break;
	}
	cout << result << "\n";
	return (0);
}