#include <iostream>
#include <map>
#include <string>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	int n, m;
	string s;
	map<int, string> list_i;
	map<string, int> list_a;

	fastio;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		list_i.insert({i, s});
		list_a.insert({s, i});
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (isalpha(s[0]))
			cout << list_a.find(s)->second << "\n";
		else
			cout << list_i.find(stoi(s))->second << "\n";
	}
	return (0);
}