#include <iostream>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int n, m;
int nums[10], input[10];
void recur(int start, int times);

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	sort(input, input + n);
	recur(0, 1);
	return (0);
}

void recur(int start, int times)
{
	if (times > m)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < nums[i]; j++)
				cout << input[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = start; i < n; i++)
	{
		nums[i]++;
		recur(i, times + 1);
		nums[i]--;
	}
}