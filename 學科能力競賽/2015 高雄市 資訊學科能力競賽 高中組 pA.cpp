#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	long long int l; cin >> l;
	if (l > 0) cout << 2 * l - 1;
	else cout << abs(l * 2);
	
}
