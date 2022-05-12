#include <iostream>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int gcd(int a, int b);
int lcm(int a, int b);

int main(void)
{
	int n, m, x, y, tc, great;

	fastio;
	cin >> tc;
	while (tc--)
	{
		cin >> n >> m >> x >> y;
		if (x == n && m == y)
		{
			cout << lcm(n, m)<<"\n";
			continue;
		}
		if (x == n)
			x = 0;
		if (y == m)
			y = 0;
		if (n > m)
		{
			for (great = x; great <= lcm(n, m); great += n)
				if (great % m == y)
					break;
		}
		else
		{
			for (great = y; great <= lcm(n, m); great += m)
				if (great % n == x)
					break;
		}
		if (great > lcm(n, m))
			cout << "-1\n";
		else
			cout << great << "\n";
	}
	return (0);
}

int lcm(int a, int b)
{
	return (a * b / gcd(a, b));
}

int gcd(int a, int b)
{
	int g, s, r;

	g = a > b ? a : b;
	s = a > b ? b : a;
	while (s > 0)
	{
		r = g % s;
		g = s;
		s = r;
	}
	return (g);
}