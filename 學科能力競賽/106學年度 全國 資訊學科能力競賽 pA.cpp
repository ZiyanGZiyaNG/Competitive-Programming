#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int n; cin >> n;
	int m[n];
	bool f = true;
	for (int i = 0; i < n; i++) cin >> m[i];
	sort(m, m + n);
	cout << m[0] << " " << m[n - 1] << " ";
	
	
	for (int i = 0; i < n - 1; i++)
	{
		if (m[i + 1] - m[i] != 1) f = false;
	}
	if (f) cout << "yes";
	else cout << "no";
	
}
