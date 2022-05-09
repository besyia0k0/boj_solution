#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#define fastio                      \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL)
using namespace std;

map<char, pair<char, char>> tree;
string preorder(char c);
string inorder(char c);
string postorder(char c);

int main(void)
{
	char self, left, right;
	int node;

    fastio;
	cin >> node;
	for (int i = 0; i < node; i++)
	{
		cin >> self >> left >> right;
		tree.insert({self, {left, right}});
	}
	cout << preorder('A') << "\n";
	cout << inorder('A') << "\n";
	cout << postorder('A') << "\n";
	return (0);
}

string preorder(char c)
{
	static string s = "";

	s.push_back(c);
	if (tree.find(c)->second.first != '.')
		preorder(tree.find(c)->second.first);
	if (tree.find(c)->second.second != '.')
		preorder(tree.find(c)->second.second);
	return (s);
}

string inorder(char c)
{
	static string s = "";

	if (tree.find(c)->second.first != '.')
		inorder(tree.find(c)->second.first);
	s.push_back(c);
	if (tree.find(c)->second.second != '.')
		inorder(tree.find(c)->second.second);
	return (s);
}

string postorder(char c)
{
	static string s = "";

	if (tree.find(c)->second.first != '.')
		postorder(tree.find(c)->second.first);
	if (tree.find(c)->second.second != '.')
		postorder(tree.find(c)->second.second);
	s.push_back(c);
	return (s);
}