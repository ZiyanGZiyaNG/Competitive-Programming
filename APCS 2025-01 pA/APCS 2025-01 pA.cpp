#include <iostream>
using namespace std;
int main()
{
	int a, b, sum = 0, n;
	cin >> a >> b;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		if (t % (a + b) < a)
		{
			sum += 0;
		}
		else if (t % (a + b) == a)
		{
			sum += b;
		}
		else if (t % (a + b) > a)
		{
			sum += b - ((t % (a + b)) - a);
		}
	}
	cout << sum;
}
