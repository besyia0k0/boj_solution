#include <iostream>
#include <vector>
#include <algorithm>
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;



int main(void)
{
	vector<int> v;
	int	result[101], arr[101];
	int len, flag, t_case, cnt;

	fastio;
	cin >> t_case;
	while (t_case--)
	{
		cin >> len;
		v.clear();
		flag = false;
		for (int i = 0; i < len; i++)
			cin >> arr[i];
		for (int i = 1; i <= len; i++)
			v.push_back(i);
		for (int i = len - 1; i >= 0; i--)
		{
			if (arr[i] >= v.size())
			{	
				flag = true;
				break;
			}
			result[i] = v[arr[i]];
			v.erase(v.begin() + arr[i]);
		}
		if (flag)
			cout << "IMPOSSIBLE\n";
		else
		{
			for (int i = 0; i < len; i++)
				cout << result[i] << " ";
			cout << "\n";
		}
	}
	return (0);
}