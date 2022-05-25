#include <iostream>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int dp[100001];

int main(void)
{
	int n;

	cin >> n;
	dp[2] = 1;
	dp[4] = 2;
	dp[5] = 1;
	for (int i = 6; i <= n; i++)
	{
		if (dp[i - 2] && dp[i - 5])
			dp[i] = min(dp[i - 2], dp[i - 5]);
		else
			dp[i] = max(dp[i - 2], dp[i - 5]);
		if (dp[i])
			dp[i]++;
	}
	if (dp[n] == 0)
		cout << "-1\n";
	else
		cout << dp[n] << "\n";
	return (0);
}