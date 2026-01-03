#include <iostream>
using namespace std;

int main() 
{
    int n; cin >> n;
    
    int a[n];
    bool vis[n];

    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        vis[i] = false;
    }

    int group = 0;

    for (int i = 0; i < n; i++) 
    {
        if (vis[i]) continue;

        group++;
        int x = i;
        while (!vis[x]) 
        {
            vis[x] = true;
            x = a[x];
        }
    }

    cout << group;
}
