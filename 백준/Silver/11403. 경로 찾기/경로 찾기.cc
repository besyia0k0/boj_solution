#include <iostream>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	int map[101][101];
	int n;

	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> map[i][j];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == i)
				continue;
			for (int k = 0; k < n; k++)
			{
				if (k != i && !map[j][k])
					map[j][k] = (map[j][i] && map[i][k] ? 1 : 0);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << map[i][j] << " ";
		cout << "\n";
	}
	return (0);
}