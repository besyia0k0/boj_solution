#include <iostream>
#include <memory.h>
#include <string>
#include <vector>

using namespace std;
int input[50][50];
int s = 0, m, n;
void     dfs(int x, int y);
void	fastio(void);

int main(void)
{
    int rep, k, x, y;

    fastio();
    cin >> rep;
    while (rep--)
    {
        s = 0;
        cin >> m >> n >> k;
        memset(input, 0, sizeof(input));
        for (int i = 0; i < k; i++)
        {
            cin >> x >> y;
            input[y][x] = 1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (input[i][j])
                {
                    dfs(i, j); s++;
                }
            }
        }
        cout << s << "\n";
    }
    return (0);
}

void    dfs(int x, int y)
{
    int x_tmp, y_tmp;
    pair<int, int>  dir[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
    pair<int, int>  elem;
    vector<pair<int, int>> stack;

    stack.push_back({ x, y });
    input[x][y] = 0;
    while (!stack.empty())
    {
        elem = stack.back();
        stack.pop_back();
        for (int i = 0; i < 4; i++)
        {
            x_tmp = elem.first + dir[i].first;
            y_tmp = elem.second + dir[i].second;
            if (x_tmp >= 0 && y_tmp >= 0 && x_tmp < n && y_tmp < m)
            {
                if (input[x_tmp][y_tmp])
                {
                    stack.push_back({ x_tmp, y_tmp });
                    input[x_tmp][y_tmp] = 0;
                }
            }
        }
    }
}

void	fastio(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}