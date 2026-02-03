#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int server[55][55];
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
        	cin >> server[i][j];
        }
        	
    }

    long long ans = LLONG_MAX;

    while (k--) 
    {
        int flow[55][55] = {0};

        for (int i = 0; i < n; i++) 
        {
            int city;
            cin >> city;
            for (int j = 0; j < m; j++) 
            {
                flow[city][j] += server[i][j];
            }
        }

        long long cost = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                if (i == j) cost += flow[i][j];
                else {
                    if (flow[i][j] >= 1000) cost += 3000 + 2 * (flow[i][j] - 1000);
                    else cost += 3 * flow[i][j];
                }
            }
        }

        ans = min(ans, cost);
    }

    cout << ans;
}
