#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long int n; cin >> n;

	if (n < 10) cout << "Y\n";
	else if (n < 1000) cout << "X\n";
	else if (n < 400000) cout << "UV\n";
	else if (n < 700000) cout << "VIS\n";
	else if (n < 1000000000) cout << "IR\n";
	else cout << "R\n";
}
