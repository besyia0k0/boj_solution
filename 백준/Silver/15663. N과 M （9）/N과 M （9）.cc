#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int n, m, tmp;
pair<vector<int>, int> nums[10];
int input[10];
vector<string> result;
set<int> unique_input;
void recur(int times);

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> input[i];
		unique_input.insert(input[i]);
	}
	sort(input, input + n);
	for (auto i : unique_input)
		nums[tmp++].second = count(input, input + n, i);
	recur(1);
	for (auto i : result)
		cout << i;
	return (0);
}

void recur(int times)
{
	if (times > m)
	{
		string s = "";
		for (int i = 1; i <= m; i++)
		{
			tmp = 0;
			for (auto j : unique_input)
			{
				if (find(nums[tmp].first.begin(), nums[tmp].first.end(), i) != nums[tmp].first.end())
				{
					s += (to_string(j) + " ");
					break;
				}
				tmp++;
			}
		}
		s += "\n";
		result.push_back(s);
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (nums[i].second)
		{
			int k = nums[i].first.size();
			nums[i].first.push_back(times);
			nums[i].second--;
			recur(times + 1);
			nums[i].first.erase(nums[i].first.begin() + k);
			nums[i].second++;
		}
	}
}