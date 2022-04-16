#include <iostream>
#include <string>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	string s;
	int result, uni, tmp, idx = 0;

    fastio;
	cin >> s;
	while (idx < s.length())
	{
		if (idx < s.length() && s[idx] == '-')
		{
			uni = 0;
			tmp = 0;
			idx++;
			while (idx < s.length() && s[idx] != '-')
			{
				if (idx < s.length() && s[idx] == '+')
				{
					uni += tmp;
					tmp = 0;
				}
				else
					tmp = tmp * 10 + s[idx] - '0';
				idx++;
			}
			uni += tmp;
			result -= uni;
		}
		else if (idx < s.length() && s[idx] == '+')
		{
			tmp = 0;
			idx++;
			while (idx < s.length() && s[idx] != '+' && s[idx] != '-')
			{
				tmp = tmp * 10 + s[idx] - '0';
				idx++;
			}
			result += tmp;
		}
		else
		{
			tmp = 0;
			while (idx < s.length() && s[idx] != '+' && s[idx] != '-')
			{
				tmp = tmp * 10 + s[idx] - '0';
				idx++;
			}
			result = tmp;
		}
	}
	cout << result << "\n";
	return (0);
}