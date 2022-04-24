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
bool max_comp(string x, string y);

int main(void)
{
	vector<string> lst, tmp_lst, plus_lst;
	string result, tmp;
	int n, m, plus_ele;

	fastio;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		lst.push_back(tmp);
	}
	sort(lst.begin(), lst.end(), comp);
	if (n == m)
		for (int i = 0; i < n; i++)
			cout << lst[i];
	else
	{
		plus_lst.resize(n);
		for (int i = 0; i < n; i++)
		{
			tmp_lst.clear();
			tmp_lst.resize(n, "");
			copy(lst.begin(), lst.end(), tmp_lst.begin());
			tmp_lst.push_back(lst[i]);
			sort(tmp_lst.begin(), tmp_lst.end(), comp);
			for (int j = 0; j < n + 1; j++)
				plus_lst[i] += tmp_lst[j];
		}
		plus_ele = max_element(plus_lst.begin(), plus_lst.end(), max_comp) - plus_lst.begin();
		for (int i = n; i < m; i++)
			lst.push_back(lst[plus_ele]);
		sort(lst.begin(), lst.end(), comp);
		for (int i = 0; i < m; i++)
			cout << lst[i];
	}
	return (0);
}

bool comp(string x, string y)
{
	return (x + y > y + x);
}

bool max_comp(string x, string y)
{
	if (x.length() == y.length())
		return (x < y);
	return (x.length() < y.length());
}