/* 這題用了一個超暴力的解法，題目要求1<= a ,b ,c <= 2^32 所以 1<= a^2 ,b^2 ,c^2 <= 2^64
明顯會爆開int:2^32-1 long long int:2^63−1 unsigned long long:2^64−1
但把它轉換成128位元的話，也就是__int128
他的範圍會變2^127−1
*/
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	long long int t; cin >> t;
	for (int i = 0; i < t; i++)
	{
		long long int a[3];
		cin >> a[0] >> a[1] >> a[2];
		sort(a, a + 3);
		
		__int128 xx = (__int128)a[2] * a[2];
		__int128 yy = (__int128)a[0] * a[0] + (__int128)a[1] * a[1];
		
		
		if (xx == yy) cout << "right triangle\n";
		else if (xx > yy) cout << "obtuse triangle\n";
		else cout << "acute triangle\n";
	}
}
