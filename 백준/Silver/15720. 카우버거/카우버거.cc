#include <iostream>
#include <set>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	int a, b, c, tmp, disc_tot = 0, disc_origin = 0, tot = 0, min;
	multiset<int, greater<int>> a_lst, b_lst, c_lst;

	fastio;
	cin >> a >> b >> c;
	min = (a > b ? b : a);
	min = (min > c ? c : min);
	for (int i = 0; i < a; i++)
	{
		cin >> tmp;
		tot += tmp;
		a_lst.insert(tmp);
	}
	for (int i = 0; i < b; i++)
	{
		cin >> tmp;
		tot += tmp;
		b_lst.insert(tmp);
	}
	for (int i = 0; i < c; i++)
	{
		cin >> tmp;
		tot += tmp;
		c_lst.insert(tmp);
	}
	auto ait = a_lst.begin(), bit = b_lst.begin(), cit = c_lst.begin();
	for (int i = 0; i < min; i++)
	{
		disc_tot += *ait - (*ait / 10) + *bit - (*bit / 10) + *cit - (*cit / 10);
		disc_origin += *ait + *bit + *cit;
		ait++;
		bit++;
		cit++;
	}
	cout << tot << "\n"<< disc_tot + (tot - disc_origin) << "\n";
	return (0);
}