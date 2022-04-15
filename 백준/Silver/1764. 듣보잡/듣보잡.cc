#include <iostream>
#include <set>
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
	set<string> cnt_h;
	set<string> result;

	fastio;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> s;
		cnt_h.insert(s);
	}
	for (int i = 0; i < m; i++)
	{
		cin >> s;
		if (cnt_h.find(s) != cnt_h.end())
			result.insert(s);
	}
	cout << result.size() << "\n";
	for (auto i : result)
		cout << i << "\n";
	return (0);
}