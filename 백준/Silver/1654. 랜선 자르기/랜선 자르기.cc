#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void	fastio(void);
bool	check(vector<int> lines, int len, int goal);

int main(void)
{
	vector<int> lines;
	int n, make, ret = 0;
	long long	tmp, min = INT_MAX, max = 0;

	cin >> n >> make;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		lines.push_back(tmp);
		max += tmp;
		if (tmp < min)
			min = tmp;
	}
	min /= make;
	max /= make;
	tmp = (min + max) / 2;
	if (!tmp)
		tmp = 1;
	while (min <= max)
	{
		tmp = (min + max) / 2;
		if (!tmp)
			tmp = 1;
		if (check(lines, tmp, make))
		{
			ret = ((ret > tmp) ? ret : tmp);
			min = tmp + 1;
		}
		else
		{
			max = tmp - 1;
		}
	}
	cout << ret << "\n";
	return (0);
}

bool	check(vector<int> lines, int len, int goal)
{
	int ret = 0;
	for (auto i : lines)
		ret += i / len;
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