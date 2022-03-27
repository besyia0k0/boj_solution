#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string>	word;

void	fastio(void);
void	find_string(string s);

int main(void)
{
    int	num;
	string	tmp;
	
	fastio();
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> tmp;
		find_string(tmp);
	}
	cout << word.size() << "\n";
	return (0);
}

void	find_string(string s)
{
	int	vec_size = word.size();
	int	str_size = s.length();

	for (int i = 0; i < vec_size; i++)
	{
		if (word[i].length() == str_size)
		{
			int idx = s.find(word[i][0]);
			while (idx != string::npos)
			{
				if (s.substr(idx) == word[i].substr(0, str_size - idx))
				{
					if (s.substr(0, idx) == word[i].substr(str_size - idx))
						return ;
				}
				idx = s.find(word[i][0], idx + 1);
			}
		}
	}
	word.push_back(s);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}