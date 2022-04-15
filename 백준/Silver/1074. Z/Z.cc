#include <iostream>
#include <cmath>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;
int recur(int times, int x, int y);

int main(void)
{
	int n, x, y;

	cin >> n >> x >> y;
	cout << recur(n - 1, x, y) << "\n";
	return (0);
}

int recur(int times, int x, int y)
{
	int x_tmp = (int)pow(2, times), y_tmp = (int)pow(2, times);
	static int start = 0;

	if (times < 0)
		return (start);
	if (x >= x_tmp)
	{
		if (y >= y_tmp)
			start += (int)pow(2, times * 2) * 3;
		else
		{
			start += (int)pow(2, times * 2) * 2;
			y_tmp = 0;
		}
	}
	else
	{
		if (y >= (int)pow(2, times))
		{
			start += (int)pow(2, times * 2) * 1;
			x_tmp = 0;
		}
		else
		{
			x_tmp = 0;
			y_tmp = 0;
		}
	}
	recur(times - 1, x - x_tmp, y - y_tmp);
	return (start);
}