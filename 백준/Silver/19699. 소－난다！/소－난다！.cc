#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

void	fastio(void);
int	isprime(int x);

int main(void)
{
	int		num[10];
	int		n, m, tot, tmp;
	vector<int>	comb;
	set<int> ret;

	fastio();
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		num[i] = tmp;
		if (i < n)
			comb.push_back(1);
		else
			comb.push_back(0);
	}
	sort(comb.begin(), comb.end());
	do {
		tot = 0;
		for (int i = 0; i < m; i++)
		{
			if (comb[i])
				tot += num[i];
		}
		if (tot < 2 || (tot > 2 && tot % 2 == 0))
			continue;
		if (isprime(tot))
			ret.insert(tot);
	} while (next_permutation(comb.begin(), comb.end()));
	if (ret.size() == 0)
	{	cout << "-1\n";	return (0);	}
	for (auto i = ret.begin(); i != ret.end();)
	{
		cout << *i;
		if (++i != ret.end())
			cout << " ";
	}
	cout << "\n";
	return (0);
}

int	isprime(int x)
{
	for (int i = 3; i <= (int)sqrt(x); i++)
	{
		if (x % i == 0)
			return (0);
	}
	return (1);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}