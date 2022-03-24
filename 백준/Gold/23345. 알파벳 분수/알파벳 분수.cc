#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

void	fastio(void);

int		main(void)
{
  int  index = 0, cur = 1;
  int  count = 0;
  string result = "";
  string s;
  set<char> top;
  set<char> bottom;
  vector<string> stk;

  fastio();
  cin >> s;
  while (s[index] != '/')
    top.insert(s[index++]);
  index++;
  while (index < s.length())
    bottom.insert(s[index++]);
  if (*top.begin() != 'A' || top.find('B') != top.end())
  {  
    cout << "None\n";
    return (0);
  }
  stk.push_back("A");
  top.erase(top.begin());
  for (int i = 1; i < s.length() - 1; i++)
  {
    if (cur == 1)
    {
      if (*bottom.begin() == ('A' + i))
      {
        string tmp(1, (*bottom.begin()));
        stk.push_back(tmp);
        bottom.erase(bottom.begin());
        cur = 2;
      }
      else
      {
        string a = stk.back();
        stk.pop_back();
        string str = "(" + stk.back() + "/" + a + ")";
        stk.pop_back();
        stk.push_back(str);
        string tmp(1, (*top.begin()));
        stk.push_back(tmp);
        top.erase(top.begin());
      }
    }
    else
    {
      if (*top.begin() == ('A' + i))
      {
        string tmp(1, (*top.begin()));
        stk.push_back(tmp);
        top.erase(top.begin());
        cur = 1;
      }
      else
      {
        string a = stk.back();
        stk.pop_back();
        string str = "(" + stk.back() + "/" + a + ")";
        stk.pop_back();
        stk.push_back(str);
        string tmp(1, (*bottom.begin()));
        stk.push_back(tmp);
        bottom.erase(bottom.begin());
      }
    }
  }
  int tot_length = stk.size();
  for (int i = 0; i < tot_length;i++)
  {
    if (i != tot_length - 1)
    {
      result = result + "(" + stk.front() + "/";
      count++;
    }
    else
    {
      result = result + stk.front();
    }
    stk.erase(stk.begin());
  }
  while (count--) result += ")";
  cout << result << "\n";
  return (0);
}

void	fastio(void)
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
}