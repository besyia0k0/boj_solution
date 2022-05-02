#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int n, m, tmp;
int use[10];
vector<int> input, queue;
vector<string> result;
void recur(int start, int times);

int main(void)
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		input.push_back(tmp);
	}
	sort(input.begin(), input.end());
	input.erase(unique(input.begin(), input.end()), input.end());
	recur(0, 1);
	for (auto i : result)
		cout << i;
	return (0);
}

void recur(int start, int times)
{
	if (times > m)
	{
		string s = "";
		for (int i = 0; i < queue.size(); i++)
		{
			s += to_string(queue[i]) + " ";
		}
		s += "\n";
		result.push_back(s);
		return;
	}
	for (int i = start; i < input.size(); i++)
	{
		queue.push_back(input[i]);
		recur(i, times + 1);
		queue.pop_back();
	}
}