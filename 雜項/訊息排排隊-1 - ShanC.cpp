// https://zerojudge.tw/ShowProblem?problemid=q908
#include <iostream>
using namespace std;
int main()
{
	long long int p, c, t; cin >> p >> c >> t;
	if (c >= p) cout << 0;
	else cout << (p - c) * t;
}
