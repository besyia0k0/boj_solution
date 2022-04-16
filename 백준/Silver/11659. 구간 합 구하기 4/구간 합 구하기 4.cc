#include <iostream>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	long long arr[100002];
	int arr_num, rep, start, end;

	fastio;
	cin >> arr_num >> rep;
	arr[0] = 0;
	for (int i = 1; i <= arr_num; i++)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	while (rep--)
	{
		cin >> start >> end;
		cout << arr[end] - arr[start - 1] << "\n";
	}
	return (0);
}