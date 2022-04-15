#include <iostream>
#include <limits.h>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

short map[501][501];
short b_size[257];

int main(void)
{
	int n, m, max, max_idx, block, time = INT_MAX, tmp_time, height = -1, tmp_block;

	cin >> n >> m >> block;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			b_size[map[i][j]]++;
		}
	for (int i = 0; i <= 256; i++)
		if (b_size[i] >= max)
		{
			max_idx = i;
			max = b_size[i];
		}
	for (int i = 0; i <= 256; i++)
	{
		tmp_time = 0;
		tmp_block = block;
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				if (map[j][k] > i)
				{
					tmp_time += (map[j][k] - i) * 2;
					tmp_block += map[j][k] - i;
				}
		for (int j = 0; j < n; j++)
			for (int k = 0; k < m; k++)
				if (map[j][k] < i)
				{
					if (tmp_block >= i - map[j][k])
					{
						tmp_time += i - map[j][k];
						tmp_block -= i - map[j][k];
					}
					else
					{
						tmp_block = -1;
						break;
					}
				}
		if (tmp_block != -1)
			if (tmp_time < time || (tmp_time == time && i > height))
			{
				height = i;
				time = tmp_time;
			}
	}
	cout << time << " " << height << "\n";
	return (0);
}