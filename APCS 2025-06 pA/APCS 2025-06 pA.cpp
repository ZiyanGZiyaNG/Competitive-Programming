#include <iostream>
using namespace std;
int main()
{
	int k, x1, y1, x2, y2, loc = 0;
	cin >> k;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	for (int i = 0; i < 9999; i++)
	{
		loc += k;
		if (loc % x1 == 0)
		{
			k -= y1;
		}

		if (loc % x2 == 0)
		{

			k -= y2;
		}

		if (k <= 0)
		{
			cout << loc;
			break;
		}
	}
}
