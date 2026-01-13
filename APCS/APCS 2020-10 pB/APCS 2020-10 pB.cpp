#include <iostream>
using namespace std;
int main()
{
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	int r, c, k, m; cin >> r >> c >> k >> m;
	int a[r][c];
	int temp[r][c];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> a[i][j];
		}
	}
	
	for (int d = 0; d < m; d++)
	{
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				temp[i][j] = a[i][j];
			}
		}
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (a[i][j] == -1) continue;
				int move = a[i][j] / k;
				
				for (int t = 0; t < 4; t++)
				{
					
					int x = i + dx[t];
					int y = j + dy[t];
					if (x >= 0 and x < r and y >= 0 and y < c and a[x][y] != -1)
					{
						temp[x][y] += move;
						temp[i][j] -= move;
					}
				}
			}
		}
		
		
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				a[i][j] = temp[i][j];
			}
		}
	}
	
	int mn = 99999, mx = -999999;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (a[i][j] > mx and a[i][j] != -1)
			{
				mx = a[i][j];
			}
			if (a[i][j] < mn and a[i][j] != -1)
			{
				mn = a[i][j];
			}
		}
	}
	cout << mn << "\n";
	cout << mx << "\n";
}
