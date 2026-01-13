#include <iostream>
using namespace std;
int main()
{
	int n; cin >> n;
	int dp_A[n];
	int dp_B[n];
  

	dp_A[0] = 1;
	dp_B[0] = 0;
  

	for (int i = 1; i <= n; i++)
  	{
		dp_A[i] = dp_B[i - 1];
    	dp_B[i] = dp_A[i - 1] + dp_B[i - 1];
  	}

  	cout << dp_A[n] << " " << dp_B[n];
}
