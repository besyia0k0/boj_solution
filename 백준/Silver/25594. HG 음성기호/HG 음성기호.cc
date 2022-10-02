#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define fastio                        \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

int main(void)
{
	map<char, string> dict;
	string s;
	string result;
	bool end = true;
	
	dict = {{'a', "aespa"},
	{'b', "baekjoon"},
	{'c', "cau"},
	{'d', "debug"},
	{'e', "edge"},
	{'f', "firefox"},
	{'g', "golang"},
	{'h', "haegang"},
	{'i', "iu"},
	{'j', "java"},
	{'k', "kotlin"},
	{'l', "lol"},
	{'m', "mips"},
	{'n', "null"},
	{'o', "os"},
	{'p', "python"},
	{'q', "query"},
	{'r', "roka"},
	{'s', "solvedac"},
	{'t', "tod"},
	{'u', "unix"},
	{'v', "virus"},
	{'w', "whale"},
	{'x', "xcode"},
	{'y', "yahoo"},
	{'z', "zebra"}};

	cin >> s;
	for (int i = 0; i < s.length(); i++)
	{
		map<char, string>::iterator iter = dict.find(s[i]);
		if (iter->second == s.substr(i, iter->second.length()))
			result.push_back(iter->first);
		else
		{
			end = false;
			break;
		}
		i += iter->second.length() - 1;
	}
	if (end)
	{
		cout << "It's HG!\n";
		cout << result << "\n";
	}
	else
		cout << "ERROR!\n";
	return (0);
}