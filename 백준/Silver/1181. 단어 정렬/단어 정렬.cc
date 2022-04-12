#include <iostream>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

void	fastio(void);

struct comp {
	bool operator()(const string x, const string y) const
	{
		if (x.length() == y.length())
			return (x < y);
		return (x.length() < y.length());
	}
};

int main(void)
{
	set<string, comp> list;
	string	s;
	int	n;

	fastio();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		list.insert(s);
	}
	for (auto i = list.begin(); i != list.end(); i++)
		cout << *i << "\n";
	return (0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}