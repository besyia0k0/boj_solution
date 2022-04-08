#include <iostream>
#include <string>
#include <vector>

using namespace std;
vector<vector<int>> input;
vector<int> visited;
int     dfs(void);
void	fastio(void);

int main(void)
{
    int com, n, x, y;
    
    fastio();
    cin >> com;
    cin >> n;
    input.resize(com + 1);
    visited.resize(com + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> x >> y;
        input[x].push_back(y);
        input[y].push_back(x);
    }
    cout << dfs();
    return (0);
}

int    dfs(void)
{
    int size = 0, elem;
    vector<int> stack;
    
    stack.push_back(1);
    visited[1] = 1;
    while (!stack.empty())
    {
        elem = stack.back();
        stack.pop_back();
        for (int i = 0; i < input[elem].size(); i++)
        {
            if (visited[input[elem][i]] == 0)
            {
                stack.push_back(input[elem][i]);
                visited[input[elem][i]] = 1;
                size++;
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