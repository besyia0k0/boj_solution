#include <iostream>

using namespace std;

void	fastio(void);

int main(void)
{
    int	num;
	int	tmp;
    int	square_num = 0;
    long long	add_num = 0;   

	fastio();
    cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> tmp;
		square_num += tmp * tmp;
		add_num += tmp;
	}
	add_num *= add_num;
	add_num -= square_num;
	cout << add_num/2 << "\n";
	return (0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}