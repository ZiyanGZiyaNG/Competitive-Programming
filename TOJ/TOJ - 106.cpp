#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n = 2;
	int now = 0; // o直線 1又 2左
	for (int i = 0; i < 9999999999999; i++)
	{
		n *= 2;
		n += 1;
		if (n % 71 == 0) break;
		if (n % 3 == 0) now = 1;
		else now = 2;
	}
	if (now == 1) cout << "right\n";
	else cout << "left\n";
	
}
