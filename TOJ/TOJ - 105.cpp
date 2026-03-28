#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n = 2;
	for (int i = 0; i < 25; i++)
	{
		n *= 2;
		n += 1;
	}
	cout << n;
}
