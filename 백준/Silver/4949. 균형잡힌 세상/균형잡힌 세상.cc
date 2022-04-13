#include <iostream>
#include <vector>
#include <string>
using namespace std;

void	fastio(void);

int main(void)
{
	vector<char> stk;
	string	s;
	int flag = 0;
	
	getline(cin, s);
	while (s != ".")
	{
		stk.clear();
		flag = 0;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '(' || s[i] == '[')
				stk.push_back(s[i]);
			else if (s[i] == ')' || s[i] == ']')
			{
				if (!stk.empty() && (stk.back() == s[i] - 1 || stk.back() == s[i] - 2))
					stk.pop_back();
				else
				{
					cout << "no\n";
					flag = 1;
					break;
				}
			}
		}
		if (!flag && stk.empty())
			cout << "yes\n";
		else if (!flag)
			cout << "no\n";
		getline(cin, s);
	}
	return (0);
}
void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}