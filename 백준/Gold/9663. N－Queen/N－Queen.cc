#include <iostream>
#include <vector>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

vector<int> chess;
bool visited[16];
int n, num;
void nqueen(int times);

int main(void)
{
	cin >> n;
	chess.resize(n, 0);
	nqueen(0);
	cout << num << "\n";
	return (0);
}

void nqueen(int times)
{
	int flag = 0;

	if (times >= n)
	{
		num++;
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		flag = 0;
		if (!visited[i])
		{
			for (int j = 0; j < times; j++)
			{
				if (abs(chess[j] - i) == abs(times - j))
				{
					flag = 1;
					break;
				}
			}
			if (!flag)
			{
				visited[i] = 1;
				chess[times] = i;
				nqueen(times + 1);
				visited[i] = 0;
			}
		}
	}
}