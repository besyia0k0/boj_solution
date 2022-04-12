#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void	fastio(void);

int main(void)
{
	vector<int> v, ret;
	int	n, tmp;

	fastio();
	cin >> n;
	while (n--)
	{
		cin >> tmp;
		v.push_back(tmp);
	}
	sort(v.begin(), v.end());
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		ret.push_back(upper_bound(v.begin(), v.end(), tmp) - lower_bound(v.begin(), v.end(), tmp));
	}
	for (int i = 0; i < n; i++)
		cout << ret[i] << " ";
	return (0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}