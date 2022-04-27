#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	vector<char> alphaset;
	vector<int> alpha;
	vector<string> str;
	string s;
	int n, tmp = 0, tot_tmp = 0, result = 0;

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			if (find(alphaset.begin(), alphaset.end(), s[j]) == alphaset.end())
				alphaset.push_back(s[j]);
		}
		str.push_back(s);
	}
	for (int i = 0; i < alphaset.size(); i++)
		alpha.push_back(9 - i);
	do
	{
		tot_tmp = 0;
		for (int j = 0; j < str.size(); j++)
		{
			tmp = 0;
			for (int k = 0; k < str[j].length(); k++)
				tmp = tmp * 10 + alpha[find(alphaset.begin(), alphaset.end(), str[j][k]) - alphaset.begin()];
			tot_tmp += tmp;
		}
		if (result < tot_tmp)
			result = tot_tmp;
	} while (prev_permutation(alpha.begin(), alpha.end()));
	cout << result << "\n";
	return (0);
}