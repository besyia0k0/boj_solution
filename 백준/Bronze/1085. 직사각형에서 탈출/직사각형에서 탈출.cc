#include <iostream>
using namespace std;

int main(void)
{
	int x, y, width, height;

	cin >> x >> y >> width >> height;
	x = (x > abs(x - width)) ? abs(x - width) : x;
	y = (y > abs(y - height)) ? abs(y - height) : y;
	cout << ((x > y) ? y : x) << "\n";
	return (0);
}