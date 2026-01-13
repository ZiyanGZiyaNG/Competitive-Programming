#include <iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int sum = 1;
	for (int i = 2; i * i < n; i++)
	{
		if (n % i == 0)
		{
			sum += i;
			sum += n / i;
		}
	}
	cout << sum << endl;
	if (n == sum)
	{
		cout << "perfect";
	}
	else
	{
		cout << "not perfect";
	}
}               
