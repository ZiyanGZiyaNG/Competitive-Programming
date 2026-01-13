#include <iostream>
using namespace std;
int main()
{
	long long int n, m;
	cin >> n >> m;
	long long int sum = n;
	while (true)
	{
		if (sum > m)
		{
			break;
		}
		cout << sum << endl;
		sum *= n;
	}
}               
