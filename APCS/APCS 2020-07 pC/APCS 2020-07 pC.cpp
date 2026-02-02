#include <iostream>
using namespace std;

int main()
{

    int n, m;
    cin >> n >> m;

    long long int p[2 * n];
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        p[n + i] = p[i];
    }

    long long int pr[2 * n];
    pr[0] = p[0];
    for (int i = 1; i < 2 * n; i++)
    {
        pr[i] = pr[i - 1] + p[i];
    }

    int pos = 0;

    for (int i = 0; i < m; i++)
    {
        long long q;
        cin >> q;

        
        long long base = (pos == 0 ? 0 : pr[pos - 1]);
        long long t = base + q;

   
        int l = pos;
        int r = pos + n - 1;

        int ans = r;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (pr[mid] >= t)
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        pos = (ans + 1) % n;
    }

    cout << pos;
}
