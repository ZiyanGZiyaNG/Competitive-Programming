#include <iostream>
#include <string>
using namespace std;
int main()
{
	string s;
	int sum = 0;
	cin >> s;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == 'j' or s[i] == 'i') sum++;
	}
	cout << sum;
}
