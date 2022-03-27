#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

vector<pair<int, int>>	times;
void	fastio(void);
void	push(int start, int end);
int		diff(int start, int end);

int main(void)
{
	int	num, max = 0;
	int	begin = 1000, fin = 2200;
	int	start, end;

	fastio();
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> start >> end;
		push(start, end);
		for (int j = 0; j < times.size() - 1; j++)
		{
			if (diff(times[j].first, times.back().first) && diff(times.back().second, times[j].second))
			{
				times.pop_back();
				break;
			}
		}
	}
	sort(times.begin(), times.end());
	max = diff(begin, times[0].first);
	if (max < diff(times.back().second, fin))
		max = diff(times.back().second, fin);
	for (int i = 0; i < times.size() - 1; i++)
		if (max < diff(times[i].second, times[i + 1].first))
			max = diff(times[i].second, times[i + 1].first);
	cout << max << "\n";
	return (0);
}

void	push(int start, int end)
{
	int	s_time = start / 100;
	int	s_min = start % 100;
	int	e_time = end / 100;
	int	e_min = end % 100;
	int	diff = 0;

	s_min -= 10;
	if (s_min < 0)
	{
		s_min += 60;
		s_time--;
	}
	e_min += 10;
	if (e_min >= 60)
	{
		e_min -= 60;
		e_time++;
	}
	times.push_back({ s_time * 100 + s_min, e_time * 100 + e_min });
}

int	diff(int start, int end)
{
	int	s_time = start / 100;
	int	s_min = start % 100;
	int	e_time = end / 100;
	int	e_min = end % 100;
	int	diff = 0;

	if (s_time <= e_time)
	{
		diff += (e_time - s_time) * 60;
		diff += e_min - s_min;
	}
	return (diff >= 0 ? diff : 0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}