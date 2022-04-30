#include <iostream>
#include <vector>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int n, m;
int nums[10], input[10];
void recur(int times);

int main(void)
{
    fastio;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	sort(input, input + n);
	recur(1);
	return (0);
}

void recur(int times)
{
	if (times > m)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < n; j++)
				if (nums[j] == i)
					cout << input[j] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (!nums[i])
		{
			nums[i] = times;
			recur(times + 1);
			nums[i] = 0;
		}
	}
}