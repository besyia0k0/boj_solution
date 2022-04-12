#include <iostream>
#include <deque>
#include <string>
using namespace std;

void	fastio(void);

int main(void)
{
	deque<int> d;
	string	s;
	int	input, n;

	fastio();
	cin >> n;
	while (n--)
	{
		cin >> s;
		if (s[1] == 'u')
			cin >> input;
		switch (s[0])
		{
		case 's':
			cout << d.size() << "\n";
			break;
		case 'e':
			cout << d.empty() << "\n";
			break;
		case 'f':
			if (d.empty())
				cout << "-1\n";
			else
				cout << d.front() << "\n";
			break;
		case 'b':
			if (d.empty())
				cout << "-1\n";
			else
				cout << d.back() << "\n";
			break;
		case 'p':
			if (s[1] == 'u')
			{
				if (s[5] == 'f')
					d.push_front(input);
				else
					d.push_back(input);
			}
			else
			{
				if (s[4] == 'f')
				{
					if (d.empty())
						cout << "-1\n";
					else
					{
						cout << d.front() <<"\n";
						d.pop_front();
					}
				}
				else
				{
					if (d.empty())
						cout << "-1\n";
					else
					{
						cout << d.back() << "\n";
						d.pop_back();
					}
				}
			}
		}
	}
	return (0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}