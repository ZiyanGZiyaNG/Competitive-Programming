#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int e, m, s; cin >> e >> m >> s;
	double ss, p; cin >> ss >> p;
	double in; cin >> in;
	if (in <= (20 * (e * 1.25 + m * 2 + s * 1) / (15 * 4.25)) + (ss * 0.4) + (p * 0.4))
	{
		cout << "YA";
	}
	else cout << "QQ";
}


