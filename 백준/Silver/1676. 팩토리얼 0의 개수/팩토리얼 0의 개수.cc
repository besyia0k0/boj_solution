#include <iostream>
#include <cmath>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int n_sqrt(int i, int root);

typedef struct num
{
	int five = 0;
	int two = 0;
	int ten = 0;
} Num;

int main(void)
{
	Num nu[501];
	int n, tmp, tot = 0;

	cin >> n;
	for (int i = 2; i <= n; i++)
	{
		tmp = i;
		nu[i] = nu[i - 1];
		if (tmp % 10 == 0)
		{
			nu[i].ten += n_sqrt(tmp, 10);
			tmp /= (int)pow(10, n_sqrt(tmp, 10));
		}
		if (tmp % 2 == 0)
		{
			nu[i].two += n_sqrt(tmp, 2);
			tmp /= (int)pow(2, n_sqrt(tmp, 2));
		}
		if (tmp % 5 == 0)
		{
			nu[i].five += n_sqrt(tmp, 5);
			tmp /= (int)pow(5, n_sqrt(tmp, 5));
		}
	}
	tot += nu[n].ten;
	tot += ((nu[n].five > nu[n].two) ? nu[n].two : nu[n].five);
	cout << tot << "\n";
	return (0);
}

int n_sqrt(int i, int root)
{
	if (i % root)
		return (0);
	return (1 + n_sqrt(i / root, root));
}