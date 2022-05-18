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
	int r, c, cur_top = 1, cur_next = 5, tmp;
	bool dir = true; // right == true, left == false
	long long result = 0;
	string fiveR_twoL = "14631463", fiveL_twoR = "13641364", oneR_sixL = "24532453", oneL_sixR = "23542354", threeR_fourL = "21562156", threeL_fourR = "26512651";

	cin >> r >> c;
	for (int i = 0; i < r; i++)
	{
		switch (cur_next)
		{
		case 1:
		case 6:
			if ((dir && cur_next == 1) || (!dir && cur_next == 6))
			{
				result += c / 4 * 14;
				auto it = oneR_sixL.find('0' + cur_top);
				for (int j = 0; j < c % 4; j++)
				{
					cur_top = oneR_sixL[it++] - '0';		
					result += cur_top;
				}
			}
			else
			{
				result += c / 4 * 14;
				auto it = oneL_sixR.find('0' + cur_top);
				for (int j = 0; j < c % 4; j++)
				{
					cur_top = oneL_sixR[it++] - '0';		
					result += cur_top;
				}
			}
			break;
		case 2:
		case 5:
			if ((dir && cur_next == 2) || (!dir && cur_next == 5))
			{
				result += c / 4 * 14;
				auto it = fiveL_twoR.find('0' + cur_top);
				for (int j = 0; j < c % 4; j++)
				{
					cur_top = fiveL_twoR[it++] - '0';		
					result += cur_top;
				}
			}
			else
			{
				result += c / 4 * 14;
				auto it = fiveR_twoL.find('0' + cur_top);
				for (int j = 0; j < c % 4; j++)
				{
					cur_top = fiveR_twoL[it++] - '0';		
					result += cur_top;
				}
			}
			break;
		case 3:
		case 4:
			if ((dir && cur_next == 3) || (!dir && cur_next == 4))
			{
				result += c / 4 * 14;
				auto it = threeR_fourL.find('0' + cur_top);
				for (int j = 0; j < c % 4; j++)
				{
					cur_top = threeR_fourL[it++] - '0';		
					result += cur_top;
				}
			}
			else
			{
				result += c / 4 * 14;
				auto it = threeL_fourR.find('0' + cur_top);
				for (int j = 0; j < c % 4; j++)
				{
					cur_top = threeL_fourR[it++] - '0';		
					result += cur_top;
				}
			}
			break;
		}
		tmp = 7 - cur_top;
		cur_top = cur_next;
		cur_next = tmp;
		dir = !dir;
	}
	cout << result << "\n";
	return (0);
}