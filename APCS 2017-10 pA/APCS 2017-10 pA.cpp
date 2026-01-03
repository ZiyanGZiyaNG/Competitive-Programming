#include <iostream>
using namespace std;
int main()
{
	int a, b, c; cin >> a >> b >> c;
	if (a != 0) a = 1;
	if (b != 0) b = 1;
	
	bool bigpy = false;
	if ((a and b) == c)
	{
		cout << "AND\n";
		bigpy = true;
	}
	if ((a or b) == c)
	{
		cout << "OR\n";
		bigpy = true;
	}
	if ((a xor b) == c)
	{
		cout << "XOR\n";
		bigpy = true;
	}
	
	if (!bigpy) cout << "IMPOSSIBLE";
	
}
