#include <bits/stdc++.h>
using namespace std;
int main()
{
	int p;
	while (cin >> p)
	{
		for (int i = 1; i <= 2 * p - 1; i++)
		{
			int level = i;
			if (i > p) level = 2 * p - i;
			for (int j = 0; j < p - level; j++) cout << " ";
			for (int j = 0; j < level; j++) cout << char('A' + j);
			for (int j = level - 2; j >= 0; j--) cout << char('A' + j);
			cout << '\n';
			
		}
	}
}
