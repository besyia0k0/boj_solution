#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int dp[1001][1001];

int main(void)
{
	int n, k;

	cin >> n >> k;
	if (2 * k > n)
		k = n - k;
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 1; i < n; i++)
	{
		dp[i][0] = 1;
		dp[i][1] = i;
		for (int j = 2; j <= min(k, i); j++)
		{
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % 10007;
		}
	}
	if (n == 1)
		cout << dp[n][k];
	else
		cout << (dp[n - 1][k] + dp[n - 1][k - 1]) % 10007;
	return (0);
}