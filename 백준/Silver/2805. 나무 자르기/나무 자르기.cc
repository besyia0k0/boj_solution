#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
using namespace std;

void	fastio(void);
bool	check(vector<int> tree, long long tmp_len, int goal);

int main(void)
{
	vector<int> tree;
	int n, len;
	long long	min = 0, max = 0, tmp, ret = 0;
	
	fastio();
	cin >> n >> len;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		tree.push_back(tmp);
		if (tmp > max)
			max = tmp;
	}
	while (min <= max)
	{
		tmp = (max + min) / 2;
		if (check(tree, tmp, len))
		{
			ret = ((ret > tmp) ? ret : tmp);
			min = tmp + 1;
		}
		else
			max = tmp - 1;
	}
	cout << ret << "\n";
	return (0);
}

bool	check(vector<int> tree, long long tmp_len, int goal)
{
	long long ret = 0;
	for (auto i : tree)
		ret += ((i - tmp_len) > 0? i - tmp_len : 0);
	if (ret >= goal)
		return (true);
	return (false);
}
void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}