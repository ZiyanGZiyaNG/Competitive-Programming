#include <iostream>
using namespace std;
int n, m, k;
int c(int n, int m, int t)
{
	if(t == k) return m % n;
	return (c(n - 1, m, t + 1) + m) % n;
}

int main()
{

	cin >> n >> m >> k;
	
	cout << c(n, m, 1) + 1;

}
