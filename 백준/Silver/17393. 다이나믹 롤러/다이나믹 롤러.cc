#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void	fastio(void);

int main(void)
{
	vector<long long>	a, b, ret;
	long long	n, tmp, size;
	
	fastio();
	cin >> n;
	for (int i = 0; i < n; i++)	{
		cin >> tmp;
		a.push_back(tmp);
	}
	for (int i = 0; i < n; i++)	{
		cin >> tmp;
		b.push_back(tmp);
	}
	for (int i = 0; i < n; i++) {
		size = upper_bound(b.begin(), b.end(), a[i]) - b.begin() - i - 1;
		size < 0 ? size = 0 : size = size;
		cout << size;
		if (i != n - 1)
			cout << " ";
	}
	cout << "\n";
	return (0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}