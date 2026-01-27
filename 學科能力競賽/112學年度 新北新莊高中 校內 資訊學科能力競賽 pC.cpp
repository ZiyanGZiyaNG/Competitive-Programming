#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n; cin >> n;
	vector<string> v;
	
	for (int i = 0; i < n; i++)
	{
		string g, na;
		cin >> g >> na;
		bool used = false;
		
		for (int j = 0; j < v.size(); j++)
		{
			if (v[j] == g) used = true;
		}	
		
		
		if (!used) cout << "welcome, " << na << "\n";
		else cout << na << " account has been used\n";
		v.push_back(g);
	}
	
}
