#include <iostream>
#include <string>
#include <vector>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

string test(string order, int arr_size, string str_arr);
int main(void)
{
	int testcase, arr_size;
	string order, str_arr;

	fastio;
	cin >> testcase;
	while (testcase--)
	{
		cin >> order >> arr_size >> str_arr;
		cout << test(order, arr_size, str_arr);
	}
	return (0);
}

string test(string order, int arr_size, string str_arr)
{
	vector<int> arr;
	string result;
	int tmp, flag = 0, start_idx = 0, end_idx = arr_size - 1;

	for (int i = 1; i < str_arr.length() - 1; i++)
	{
		tmp = 0;
		while (i < str_arr.length() - 1 && str_arr[i] != ',')
			tmp = tmp * 10 + str_arr[i++] - '0';
		arr.push_back(tmp);
	}

	for (int i = 0; i < order.length(); i++)
	{
		if (order[i] == 'R')
		{
			swap(start_idx, end_idx);
			flag > 0 ? flag = 0 : flag = 1;
		}
		else
		{
			if ((!flag && start_idx > end_idx) || (flag && start_idx < end_idx))
				return ("error\n");
			if (!flag)
				start_idx++;
			else
				start_idx--;
		}
	}
	result = "[";
	if (!flag)
		for (int i = start_idx; i <= end_idx; i++)
		{
			result.append(to_string(arr[i]));
			result.push_back(',');
		}
	else
		for (int i = start_idx; i >= end_idx; i--)
		{
			result.append(to_string(arr[i]));
			result.push_back(',');
		}
	if (result.length() > 1)
		result.pop_back();
	result.append("]\n");
	return (result);
}