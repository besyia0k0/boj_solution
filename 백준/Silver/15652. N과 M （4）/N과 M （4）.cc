#include <iostream>
#include <vector>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int n, m;
int nums[10];
void recur(int start, int times);

int main(void)
{
	cin >> n >> m;
	recur(1, 0);
	return (0);
}

void recur(int start, int times)
{
	if (times == m)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < nums[i]; j++)
				cout << i << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = start; i <= n; i++)
	{
		nums[i]++;
		recur(i, times + 1);
		nums[i]--;
	}
}