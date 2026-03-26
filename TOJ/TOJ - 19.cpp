#include <bits/stdc++.h>
using namespace std;
int main()
{
	double x1;
	while (cin >> x1)
	{
		double y1, r1, x2, y2, r2; cin >> y1 >> r1 >> x2 >> y2 >> r2;
		double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
		if (d <= r1 + r2) cout << "Quick in\n";
		else cout << "Nearly\n";
	}
}
