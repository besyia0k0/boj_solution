#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void  fastio(void);

int		main(void)
{
	int			player_num;
	long long	tmp;
	long long	me;
	vector<long long> players;
	
	fastio();
	cin >> player_num;
	cin >> me;
	for (int i = 1; i < player_num; i++)
	{
		cin >> tmp;
		players.push_back(tmp);
	}
	sort(players.begin(), players.end());
	while (players.size() && players.back() >= me)
	{
		auto it = lower_bound(players.begin(), players.end(), me);
		if (it == players.begin())
		{
			cout << "No\n";
			return (0);
		}
		it--;
		me += *it;
		players.erase(it);
	}
	cout << "Yes\n";
	return (0);
}


void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}