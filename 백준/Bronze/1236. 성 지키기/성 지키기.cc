#include <iostream>
#include <memory.h>
#include <vector>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	char	map[52][52];
	short	width[52];
	short	height[52];
	int 	n, m, w = 0, h = 0;

	fastio;
	cin >> n >> m;
	memset(width, 0, sizeof(width));
	memset(height, 0, sizeof(height));
	for (int i = 0; i < n; i++)
		cin >> map[i];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == 'X')
			{
				width[j] = 1;
				height[i] = 1;
			}
	for (int i = 0; i < n; i++)
		if (height[i])
			h++;
	for (int i = 0; i < m; i++)
		if (width[i])
			w++;
	cout << (n - h < m - w ? m - w : n - h) << "\n";
	return (0);
}