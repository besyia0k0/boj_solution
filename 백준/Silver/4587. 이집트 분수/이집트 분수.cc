#include <iostream>
#include <numeric>

using namespace std;

int main(void)
{
	long long	n, m, n_tmp, m_tmp, big, tmp_gcd;
	
	while (1)
	{
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;
		while (n != 0)
		{
			big = m / n;
			if (m % n)
				big++;
			n_tmp = big * n - m;
			m_tmp = big * m;
			tmp_gcd = gcd(n_tmp, m_tmp);
			n_tmp /= tmp_gcd;
			m_tmp /= tmp_gcd;
			while (m_tmp >= 1000000)
			{
			    big++;
			    n_tmp = big * n - m;
		    	m_tmp = big * m;
			    tmp_gcd = gcd(n_tmp, m_tmp);
			    n_tmp /= tmp_gcd;
			    m_tmp /= tmp_gcd;
			}
			n = n_tmp;
			m = m_tmp;
			cout << big;
			if (n != 0)
				cout << " ";
		}
		cout << "\n";
	}
	return (0);
}