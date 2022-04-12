#include <iostream>
#include <string>
using namespace std;

void	fastio(void);

int main(void)
{
	string n, tmp;
	int num, times = 1, ret = 0;

	fastio();
	cin >> n;
	num = stoi(n);
	for (int i = ((num - (n.length() * 9)) > 0 ? (num - (n.length() * 9)) : 0); i <= num; i++)
	{
		tmp = to_string(i);
		ret = i;
		for (int j = 0; j < tmp.length(); j++)
			ret += tmp[j] - '0';
		if (ret == num)
			break ;
		tmp = "0";
	}
	cout << tmp << "\n";
	return (0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}