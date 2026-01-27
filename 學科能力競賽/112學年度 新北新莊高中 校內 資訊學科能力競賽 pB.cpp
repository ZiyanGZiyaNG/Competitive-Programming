#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n; 
    cin >> n;

    vector<int> v;

    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back(max(0, max(a, b)));  
    }

    sort(v.begin(), v.end());         

    long long sum = 0;
    int len = n - 1;

    for (int i = 0; i < n; i++)
    {
        sum += v[len - i];             
        cout << sum << "\n";
    }
}
