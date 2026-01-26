#include <iostream>
using namespace std;
int main()
{
	int q; cin >> q;
	int s = 0;
	bool m = false;
	for (int i = 0; i < q; i++)
	{
		int a; cin >> a;
		if (a == 1) s++;
		if (a == 3) 
		{
			if (m) m = false;
			else if (!m) m = true;
		}
		if (a == 2)
		{
			if (s >= 1) s--;
		}
		
		
		if (s >= 3 and m == true)
		{
			cout << "Yes\n";
		}
		else cout << "No\n";
		
	}
}
