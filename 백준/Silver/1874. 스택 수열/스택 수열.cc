#include <iostream>
#include <vector>
#include <limits.h>
#include <cmath>
using namespace std;

void	fastio(void);

int main(void)
{
	vector<int>		stack;
	vector<char>	cal;
	int	n, input, cur = 1;

	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> input;
		if (input >= cur)
		{
			for (int j = cur; j <= input; j++)
			{
				stack.push_back(j);
				cal.push_back('+');
			}
			cur = input + 1;
			stack.pop_back();
			cal.push_back('-');
		}
		else
		{
			if (stack.back() == input)
			{
				stack.pop_back();
				cal.push_back('-');
			}
			else
			{
				cout << "NO\n";
				return (0);
			}
		}
	}
	for (auto i : cal)
	{
		cout << i << "\n";
	}
	return (0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}