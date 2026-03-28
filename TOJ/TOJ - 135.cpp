#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	int c = 1;

	while (cin >> n)
	{
		if (n == 0) break;

		vector<vector<int>> v(n, vector<int>(3));
		int s = 0;

		for (int i = 0; i < n; i++)
		{
			cin >> v[i][0] >> v[i][1] >> v[i][2];
			s = max(s, v[i][1]);
		}

		bool py = false;
		int y;

		for (int i = s; i < 10000; i++)
		{
			bool ok = true;

			for (int j = 0; j < n; j++)
			{
				if ((i - v[j][1]) % (v[j][2] - v[j][1]) != v[j][0] - v[j][1])
				{
					ok = false;
					break;
				}
			}

			if (ok)
			{
				py = true;
				y = i;
				break;
			}
		}

		cout << "Case #" << c << ":\n";

		if (py)
			cout << "The actual year is " << y << ".\n";
		else
			cout << "Unknown bugs detected.\n";

		cout << '\n';

		c++;
	}
}
