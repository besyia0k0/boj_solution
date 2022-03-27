#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>

using namespace std;

vector< pair<string, string> >	times;

void	fastio(void);
int	diff(string start, string end, int flag);

int main(void)
{
	int	num, max = 0;
	string	begin("0950"), fin("2210");
	string	start, end;

	fastio();
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> start >> end;
		times.push_back(make_pair(start, end));
		for (int j = 0; j < times.size() - 1; j++)
		{
			if (diff(times[j].first, start, 0) && diff(end, times[j].second, 0))
			{
				times.pop_back();
				break;
			}
		}

	}
	sort(times.begin(), times.end());
	max = diff(begin, times[0].first, 1);
	max < diff(times.back().second, fin, 1) ? max = diff(times.back().second, fin, 1) : max;
	for (int i = 0; i < times.size() - 1; i++)
		max < diff(times[i].second, times[i + 1].first, 1) ? max = diff(times[i].second, times[i + 1].first, 1) : max;
	cout << max << "\n";
	return (0);
}

int	diff(string start, string end, int flag)
{
	string	s_time = start.substr(0, 2);
	string	s_min = start.substr(2, 2);
	string	e_time = end.substr(0, 2);
	string	e_min = end.substr(2, 2);
	int	diff = 0;

	if (flag)
	{
		s_min[0]++;
		if (s_min[0] >= '6')
		{
			s_min[0] = '0';
			s_time[1]++;
			if (s_time[1] > '9')
			{
				s_time[0]++;
				s_time[1] = '0';
			}
		}
		if (e_min[0] == '0')
		{
			if (e_time[1] == '0')
			{
				e_time[0]--;
				e_time[1] = '9';
			}
			else
				e_time[1]--;
			e_min[0] = '5';
		}
		else
			e_min[0]--;
	}
	if (s_time <= e_time)
	{
		diff += (stoi(e_time) - stoi(s_time)) * 60;
		diff += stoi(e_min) - stoi(s_min);
	}
	return (diff >= 0 ? diff : 0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}