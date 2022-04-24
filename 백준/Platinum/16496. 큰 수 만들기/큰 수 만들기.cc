#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

bool comp(string x, string y);

int main(void)
{
	vector<string> lst;
	string result, tmp;
	int n, zero = 0;

	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		if (tmp == "0")
			zero++;
		lst.push_back(tmp);
	}
	sort(lst.begin(), lst.end(), comp);
	if (zero == n)
		cout << "0";
	else
		for (int i = 0; i < n; i++)
			cout << lst[i];
	return (0);
}

bool comp(string x, string y)
{
	return (x + y > y + x);
}