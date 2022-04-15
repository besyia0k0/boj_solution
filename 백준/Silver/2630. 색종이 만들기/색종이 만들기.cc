#include <iostream>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

char paper[129][129];
int p_cnt = 1;
int white_cnt;

bool isfull(int x_idx, int y_idx, int p_size);
void count_paper(int x_idx, int y_idx, int p_size);

int main(void)
{
	int n;

	fastio;
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> paper[i][j];
	count_paper(0, 0, n);
	cout << white_cnt << "\n" << p_cnt - white_cnt << "\n";
	return (0);
}

void count_paper(int x_idx, int y_idx, int p_size)
{
	int tmp = p_size / 2;

	if (!isfull(x_idx, y_idx, p_size))
	{
		p_cnt += 3;
		count_paper(x_idx, y_idx, p_size / 2);
		count_paper(x_idx, y_idx + tmp, p_size / 2);
		count_paper(x_idx + tmp, y_idx, p_size / 2);
		count_paper(x_idx + tmp, y_idx + tmp, p_size / 2);
	}
}

bool isfull(int x_idx, int y_idx, int p_size)
{
	char c = paper[x_idx][y_idx];

	for (int i = 0; i < p_size; i++)
		for (int j = 0; j < p_size; j++)
			if (paper[x_idx + i][y_idx + j] != c)
				return (false);
	if (c == '0')
		white_cnt++;
	return (true);
}