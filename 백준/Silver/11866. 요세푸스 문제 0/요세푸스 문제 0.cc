#include <iostream>
#include <vector>
using namespace std;

void	fastio(void);

int main(void)
{
	vector<int> v;
	int	n, step, idx, check = 1;

	cin >> n >> step;
	for (int i = 1; i <=n; i++)
		v.push_back(i);
	cout << "<" << v[(step - 1) % n];
	v[(step - 1) % n] = 0;
	idx = (step - 1) % n;
	while (check != n)
	{
		for (int i = 0; i < step; i++) {
			idx++;
			if (idx >= n)
				idx -= n;
			if (!v[idx])
				i--;
		}
		cout << ", "<< v[idx];
		v[idx] = 0;
		check++;
	}
	cout << ">";
	return (0);
}