#include <iostream>
#include <string>
using namespace std;

int main(void)
{
	string n, tmp;
	int num, ret = 0;

	cin >> n;
	num = stoi(n);
	for (int i = ((num - (n.length() * 9)) > 0 ? (num - (n.length() * 9)) : 0); i <= num; i++)
	{
		tmp = to_string(i);
		ret = i;
		for (int j = 0; j < tmp.length(); j++)
			ret += tmp[j] - '0';
		if (ret == num)
			break ;
		tmp = "0";
	}
	cout << tmp << "\n";
	return (0);
}