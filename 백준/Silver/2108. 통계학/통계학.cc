#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void	fastio(void);

int main(void)
{
	vector<int>	input, cnt;
	int	n, min = 4000, max = -4000, tmp;
	long long	tot = 0;
	
	cin >> n;
	cnt.resize(8002, 0);
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp < min)
			min = tmp;
		if (tmp > max)
			max = tmp;
		tot += tmp;
		if (tmp < 0)
			cnt[tmp + 4000]++;
		else
			cnt[tmp + 4000]++;
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());
	cout << ((roundl(tot / (long double)n) == 0) ? 0 : roundl(tot / (long double)n)) << "\n";
	cout << input[n / 2] << "\n";
	auto ptr = max_element(cnt.begin(), cnt.end());
	if (ptr != cnt.end() - 1)
	{
		if (*ptr == *max_element(ptr + 1, cnt.end()))
			ptr = max_element(ptr + 1, cnt.end());
	}
	tmp = ptr - cnt.begin();
	tmp -= 4000;
	cout << tmp << "\n";
	cout << max - min << "\n";
	return (0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}