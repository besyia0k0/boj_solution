#include <iostream>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int dp[101][100001];

int main(void)
{
	int list[101][2];
	int num, max_size;

	fastio;
	cin >> num >> max_size;
	for (int i = 1; i <= num; i++)
		cin >> list[i][0] >> list[i][1];
	for (int i = 1; i <= num; i++)
	{
		for (int j = 1; j <= max_size; j++)
		{
			if (j - list[i][0] >= 0)
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - list[i][0]] + list[i][1]);
			else
				dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[num][max_size] << "\n";
	return (0);
}