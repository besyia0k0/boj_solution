#include <iostream>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

short paper[2200][2200];
int zero;
int one;
int minus_one;
void count_paper(int x, int y, int p_size);
bool is_full(int x, int y, int p_size);

int main(void)
{
	int num;

    fastio;
	cin >> num;
	for (int i = 0; i < num; i++)
		for (int j = 0; j < num; j++)
			cin >> paper[i][j];
	count_paper(0, 0, num);
	cout << minus_one << "\n" << zero << "\n" << one << "\n";
	return (0);
}

void count_paper(int x, int y, int p_size)
{
	int tmp1 = p_size / 3;
	int tmp2 = tmp1 + p_size / 3;

	if (is_full(x, y, p_size))
		return;
	count_paper(x, y, p_size / 3);
	count_paper(x, y + tmp1, p_size / 3);
	count_paper(x, y + tmp2, p_size / 3);
	count_paper(x + tmp1, y, p_size / 3);
	count_paper(x + tmp2, y, p_size / 3);
	count_paper(x + tmp1, y + tmp1, p_size / 3);
	count_paper(x + tmp1, y + tmp2, p_size / 3);
	count_paper(x + tmp2, y + tmp1, p_size / 3);
	count_paper(x + tmp2, y + tmp2, p_size / 3);
}

bool is_full(int x, int y, int p_size)
{
	short c = paper[x][y];

	for (int i = 0; i < p_size; i++)
		for (int j = 0; j < p_size; j++)
			if (paper[x + i][y + j] != c)
				return (false);
	if (c == 0)
		zero++;
	else if (c == -1)
		minus_one++;
	else
		one++;
	return (true);
}