#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	vector<int> schedule, tap;
	int tap_size, sch_size, tap_tmp = 0, pop_times = 0;

	cin >> tap_size >> sch_size;
	schedule.resize(sch_size, 0);
	tap.resize(tap_size, 0);
	for (int i = 0; i < sch_size; i++)
		cin >> schedule[i];
	for (int i = 0; i < sch_size; i++)
	{
		if (find(tap.begin(), tap.end(), schedule[i]) == tap.end())
		{
			if (tap_tmp < tap_size)
			{
				tap[tap_tmp] = schedule[i];
				tap_tmp++;
			}
			else
			{
				vector<int>::iterator it;
				vector<int>::iterator max_it = find(schedule.begin() + i + 1, schedule.end(), tap[0]);
				int flag = 1;
				for (int j = 0; j < tap_size; j++)
				{
					it = find(schedule.begin() + i + 1, schedule.end(), tap[j]);
					if (it == schedule.end())
					{
						pop_times++;
						tap[j] = schedule[i];
						flag = 0;
						break;
					}
					if (max_it < it)
					{
						max_it = it;
						flag = j + 1;
					}
				}
				if (flag)
				{
					pop_times++;
					tap[flag - 1] = schedule[i];
				}
			}
		}
	}
	cout << pop_times << "\n";
	return (0);
}