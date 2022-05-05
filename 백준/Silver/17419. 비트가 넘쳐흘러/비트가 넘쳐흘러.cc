#include <iostream>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	char input[1000001];
	int n, ret = 0;

	fastio;
	cin >> n >> input;
	for (int i = 0; i < n; i++)
	{
		if (input[i] == '1')
			ret++;
	}
	cout << ret << "\n";
	return (0);
}