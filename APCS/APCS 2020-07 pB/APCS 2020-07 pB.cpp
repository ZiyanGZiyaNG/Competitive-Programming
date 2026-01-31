#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct d 
{
    int top;
    int down;
    int front;
    int back;
    int left;
    int right;
};

int main() 
{
    int n, m;  cin >> n >> m;

    vector<d> v(n, {1, 6, 4, 3, 5, 2});

    for (int i = 0; i < m; i++) 
    {
        int a, b; cin >> a >> b;

        if (b > 0) 
        {
            swap(v[a - 1], v[b - 1]);
        } 
        else if (b == -1) 
        {
            v[a - 1] = {v[a - 1].back, v[a - 1].front, v[a - 1].top, v[a - 1].down, v[a - 1].left, v[a - 1].right};
        } 
        else if (b == -2) 
        {
            v[a - 1] = {v[a - 1].left, v[a - 1].right, v[a - 1].front, v[a - 1].back, v[a - 1].down, v[a - 1].top};
        }
    }

    for (int i = 0; i < n; i++) {
        cout << v[i].top << " ";
    }
    return 0;
}
