#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{

    int n; 
    cin >> n;

    for (int j = 0; j < n; j++) 
    {
        int m; 
        cin >> m;

       
	    int a[m];
        for (int i = 0; i < m; i++) cin >> a[i];

        int cur = a[0]; 
        int ans = a[0];   

        for (int i = 1; i < m; i++) {
            cur = max(cur + a[i], a[i]);
            ans = max(ans, cur);
        }

        cout << ans << "\n";
    }

}
