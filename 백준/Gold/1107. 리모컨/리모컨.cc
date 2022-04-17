#include <iostream>
#include <vector>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	int target, broken_num, result, tmp;
	vector<int> nums;

	for (int i = 0; i < 10; i++)
		nums.push_back(i);
	cin >> target >> broken_num;
	for (int i = 0; i < broken_num; i++)
	{
		cin >> tmp;
		nums.erase(find(nums.begin(), nums.end(), tmp));
	}
	result = (target > 100 ? target - 100 : 100 - target);
	for (int i = 0; i < nums.size(); i++)
	{
		tmp = nums[i];
		result = min(result, (target > tmp ? target - tmp + 1 : tmp - target + 1));
	}
	for (int i = 0; i < nums.size(); i++)
		for (int j = 0; j < nums.size(); j++)
		{
			tmp = nums[i] * 10 + nums[j];
			result = min(result, (target > tmp ? target - tmp + 2 : tmp - target + 2));
		}
	for (int i = 0; i < nums.size(); i++)
		for (int j = 0; j < nums.size(); j++)
			for (int k = 0; k < nums.size(); k++)
			{
				tmp = nums[i] * 100 + nums[j] * 10 + nums[k];
				result = min(result, (target > tmp ? target - tmp + 3 : tmp - target + 3));
			}
	for (int i = 0; i < nums.size(); i++)
		for (int j = 0; j < nums.size(); j++)
			for (int k = 0; k < nums.size(); k++)
				for (int l = 0; l < nums.size(); l++)
				{
					tmp = nums[i] * 1000 + nums[j] * 100 + nums[k] * 10 + nums[l];
					result = min(result, (target > tmp ? target - tmp + 4 : tmp - target + 4));
				}
	for (int i = 0; i < nums.size(); i++)
		for (int j = 0; j < nums.size(); j++)
			for (int k = 0; k < nums.size(); k++)
				for (int l = 0; l < nums.size(); l++)
					for (int m = 0; m < nums.size(); m++)
					{
						tmp = nums[i] * 10000 + nums[j] * 1000 + nums[k] * 100 + nums[l] * 10 + nums[m];
						result = min(result, (target > tmp ? target - tmp + 5 : tmp - target + 5));
					}
	for (int i = 0; i < nums.size(); i++)
		for (int j = 0; j < nums.size(); j++)
			for (int k = 0; k < nums.size(); k++)
				for (int l = 0; l < nums.size(); l++)
					for (int m = 0; m < nums.size(); m++)
						for (int n = 0; n < nums.size(); n++)
						{
							tmp = nums[i] * 100000 + nums[j] * 10000 + nums[k] * 1000 + nums[l] * 100 + nums[m] * 10 + nums[n];
							if (n > 500000)
								break;
							result = min(result, (target > tmp ? target - tmp + 6 : tmp - target + 6));
						}
	cout << result << "\n";
	return (0);
}