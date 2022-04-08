#include <iostream>
#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
vector<vector<int>> input;
int n, ret;
int dfs(int x, int y);
void	fastio(void);

int main(void)
{
    string      s;
    vector<int> size;

    fastio();
    cin >> n;
    input.resize(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        for (int j = 0; j < n; j++)
            input[i][j] = (s[j] - '0');
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (input[i][j])
            {
                size.push_back(dfs(i, j));
                ret++;
            }
    cout << ret << "\n";
    sort(size.begin(), size.end());
    for (int i = 0; i < size.size();i++)
        cout << size[i]<<"\n";
    return (0);
}

int    dfs(int x, int y)
{
    int size = 1, x_tmp, y_tmp;
    pair<int, int>  elem;
    pair<int, int>  dir[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<pair<int, int>> stack;
    
    stack.push_back({x, y});
    input[x][y] = 0;
    while (!stack.empty())
    {
        elem = stack.back();
        stack.pop_back();
        for (int i = 0; i < 4; i++)
        {
            x_tmp = elem.first + dir[i].first;
            y_tmp = elem.second + dir[i].second;
            if (x_tmp >= 0 && y_tmp >= 0 && x_tmp < n && y_tmp < n)
            {
                if (input[x_tmp][y_tmp])
                {
                    stack.push_back({x_tmp, y_tmp});
                    input[x_tmp][y_tmp] = 0;
                    size++;
                }
            }
        }
    }
    return (size);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}