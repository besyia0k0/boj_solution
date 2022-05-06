#include <iostream>
#include <vector>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

bool map[26][26];
int result, n, m;
void recur(int times);

int main(void)
{
	cin >> n >> m;
	recur(0);
	cout << result << "\n";
	return (0);
}

void recur(int times)
{
	int x = times / m, y = times % m;

	if (times == n * m)
	{
		result++;
		return;
	}
	if (!(x > 0 && y > 0 && (map[x - 1][y] && map[x][y - 1] && map[x - 1][y - 1])))
	{
		map[x][y] = true;
		recur(x * m + y + 1);
		map[x][y] = false;
	}
	map[x][y] = false;
	recur(x * m + y + 1);
	map[x][y] = false;	
}