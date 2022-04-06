#include <iostream>
#include <string>
#include <map>
#include <utility>

using namespace std;

multimap<char, string> mmap;
void	fastio(void);

int main(void)
{
	string 	s;
	int	n, m, ret = 0;
	multimap<char, string>::iterator	iter;
	
	fastio();
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		mmap.insert({s[0], s});
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		for (iter = mmap.equal_range(s[0]).first; iter != mmap.equal_range(s[0]).second; iter++)
			if (iter->second.find(s) != string::npos)
			{	ret++;	break;}
	}
	cout << ret << "\n";
	return (0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}