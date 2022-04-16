#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	string s;
	int tot_n, n, result, tmp;

	fastio;
	cin >> tot_n;
	while (tot_n--)
	{
		map<string, int> wear_num;

		cin >> n;
		result = (n == 0 ? 0 : 1);
		while (n--)
		{
			cin >> s;
			cin >> s;
			if (wear_num.find(s) == wear_num.end())
				wear_num.insert({s, 2});
			else
				wear_num[s]++;
		}
		for (auto i : wear_num)
			result *= i.second;
		cout << (result == 0 ? 0 : result - 1) << "\n";
	}
	return (0);
}