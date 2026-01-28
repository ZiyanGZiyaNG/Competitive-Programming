#include <iostream>
using namespace std;
int main()
{
	long long int c, cl, ck;
	while (cin >> c >> cl >> ck)
		cout << c << " 個餅乾，" << cl + min((c / 10), (ck / 2)) << " 盒巧克力，"<< ck << " 個蛋糕。\n";
}
