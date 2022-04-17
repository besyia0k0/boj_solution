#include <iostream>
#include <string>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

char input[65][65];
string result;
int can_zip(int x, int y, int i_size);
void check_input(int x, int y, int i_size);

int main(void)
{
	int n;

	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> input[i];
	check_input(0, 0, n);
	cout << result << "\n";
	return (0);
}

void check_input(int x, int y, int i_size)
{
	int check = can_zip(x, y, i_size);
	int tmp = i_size / 2;

	if (check >= 0)
		result.push_back(check + '0');
	else
	{
		result.push_back('(');
		check_input(x, y, tmp);
		check_input(x, y + tmp, tmp);
		check_input(x + tmp, y, tmp);
		check_input(x + tmp, y + tmp, tmp);
		result.push_back(')');
	}
}

int can_zip(int x, int y, int i_size)
{
	char c = input[x][y];

	for (int i = 0; i < i_size; i++)
	{
		for (int j = 0; j < i_size; j++)
		{
			if (input[x + i][y + j] != c)
				return (-1);
		}
	}
	return (c - '0');
}