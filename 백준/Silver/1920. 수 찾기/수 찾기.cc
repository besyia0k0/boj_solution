#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;
void	fastio(void);

int main(void)
{
	int	n, m, tmp;
	set<int>	list;
	vector<int> comp_list;

	fastio();
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		list.insert(tmp);
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> tmp;
		comp_list.push_back(tmp);
	}
	for (int i = 0; i < m; i++)
	{
		if (list.find(comp_list[i]) != list.end())
			cout << "1\n";
		else
			cout << "0\n";
	}
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}