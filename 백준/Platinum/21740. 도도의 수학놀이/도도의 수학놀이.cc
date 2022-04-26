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
bool ele_comp(string x, string y);

int main(void)
{
	vector<string> lst, plus_lst;
	string result, tmp;
	int n, m;

	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		reverse(tmp.begin(), tmp.end());
		for (int j = 0; j < tmp.length(); j++)
			if (tmp[j] == '6')
				tmp[j] = '9';
			else if (tmp[j] == '9')
				tmp[j] = '6';
		lst.push_back(tmp);
	}
	lst.push_back(*max_element(lst.begin(), lst.end(), ele_comp));
	sort(lst.begin(), lst.end(), comp);
	result = "";
	for (int i = 0; i < n + 1; i++)
		result += lst[i];
	for (int i = result.length() - 1; i >= 0; i--)
	{
		if (result[i] == '6')
			cout << "9";
		else if (result[i] == '9')
			cout << "6";
		else
			cout << result[i];
	}
	return (0);
}

bool comp(string x, string y)
{
	return (x + y > y + x);
}

bool ele_comp(string x, string y)
{
	if (x.length() == y.length())
		return (x < y);
	return (x.length() < y.length());
}