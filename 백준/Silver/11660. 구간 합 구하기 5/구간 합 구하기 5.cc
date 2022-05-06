#include <iostream>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int input[1025][1025];
int dp[1025][1025];

int main(void)
{
	int size, t_size, x1, y1, x2, y2;

	fastio;
	cin >> size >> t_size;
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			cin >> input[i][j];
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + input[i][j] - dp[i - 1][j - 1];
		}
	}
	while (t_size--)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x1 - 1][y2] - dp[x2][y1 - 1] + dp[x1 - 1][y1 - 1] << "\n";
	}
	return (0);
}