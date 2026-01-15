#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		int num = 0;
		int m; cin >> m;
		int a[m];
		for (int j = 0; j < m; j++)
		{
			cin >> a[j];
		}
		
		for (int x = 0; x < m; x++)
		{
			for (int y = 0; y < m - 1; y++)
			{
				if (a[y] > a[y + 1])
				{
					swap(a[y], a[y + 1]);
					num++;
				}
			}
		}
		cout << "Optimal train swapping takes " << num << " swaps.\n";
	}
}
