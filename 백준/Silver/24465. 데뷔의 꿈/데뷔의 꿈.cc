#include <iostream>
#include <vector>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

bool star[12];

int main(void)
{
	vector<pair<int, int>> passed;
	int month, day, rept;

	fastio;
	for (int i = 0; i < 7; i++)
	{
		cin >> month >> day;
		if ((month == 1 && day >= 20) || (month == 2 && day <= 18))
			star[0] = true;
		else if (month == 2 || (month == 3 && day <= 20))
			star[1] = true;
		else if (month == 3 || (month == 4 && day <= 19))
			star[2] = true;
		else if (month == 4 || (month == 5 && day <= 20))
			star[3] = true;
		else if (month == 5 || (month == 6 && day <= 21))
			star[4] = true;
		else if (month == 6 || (month == 7 && day <= 22))
			star[5] = true;
		else if (month == 7 || (month == 8 && day <= 22))
			star[6] = true;
		else if (month == 8 || (month == 9 && day <= 22))
			star[7] = true;
		else if (month == 9 || (month == 10 && day <= 22))
			star[8] = true;
		else if (month == 10 || (month == 11 && day <= 22))
			star[9] = true;
		else if (month == 11 || (month == 12 && day <= 21))
			star[10] = true;
		else
			star[11] = true;
	}
	cin >> rept;
	while (rept--)
	{
		cin >> month >> day;
		if (((month == 1 && day >= 20) || (month == 2 && day <= 18)) && !star[0])
			passed.push_back({month, day});
		else if (((month == 2 && day >= 19) || (month == 3 && day <= 20)) && !star[1])
			passed.push_back({month, day});
		else if (((month == 3 && day >= 21) || (month == 4 && day <= 19)) && !star[2])
			passed.push_back({month, day});
		else if (((month == 4 && day >= 20) || (month == 5 && day <= 20)) && !star[3])
			passed.push_back({month, day});
		else if (((month == 5 && day >= 21) || (month == 6 && day <= 21)) && !star[4])
			passed.push_back({month, day});
		else if (((month == 6 && day >= 22) || (month == 7 && day <= 22)) && !star[5])
			passed.push_back({month, day});
		else if (((month == 7 && day >= 23) || (month == 8 && day <= 22)) && !star[6])
			passed.push_back({month, day});
		else if (((month == 8 && day >= 23) || (month == 9 && day <= 22)) && !star[7])
			passed.push_back({month, day});
		else if (((month == 9 && day >= 23) || (month == 10 && day <= 22)) && !star[8])
			passed.push_back({month, day});
		else if (((month == 10 && day >= 23) || (month == 11 && day <= 22)) && !star[9])
			passed.push_back({month, day});
		else if (((month == 11 && day >= 23) || (month == 12 && day <= 21)) && !star[10])
			passed.push_back({month, day});
		else if (((month == 12 && day >= 22) || (month == 1 && day <= 19)) && !star[11])
			passed.push_back({month, day});
	}
	if (passed.empty())
		cout << "ALL FAILED\n";
	else
	{
		sort(passed.begin(), passed.end());
		for (auto i : passed)
			cout <<i.first << " " << i.second << "\n";
	}
	return (0);
}