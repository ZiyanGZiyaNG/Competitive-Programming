#include <iostream>
using namespace std;
int main()
{
	int p, d, t, c;
	cin >> p >> d >> t >> c;
	int sum = p;
	if (d >= 30 and c == 0)
	{
		sum -= 5;
	}
	if (d <= 15 and c == 1)
	{
		sum -= 5;
	}
	if (7 <= t and t <= 10)
	{
		sum -= 5;
	}
	if (14 <= t and t <= 16)
	{
		sum -= 5;
	}
	cout << sum;	
}
