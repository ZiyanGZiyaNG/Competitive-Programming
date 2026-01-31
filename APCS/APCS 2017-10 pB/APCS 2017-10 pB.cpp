#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int k; cin >> k;
    string s; cin >> s;

    int n = s.size();
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z') a[i] = 1;
        else a[i] = 0;
    }

    vector<int> v;
    int cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] == a[i - 1]) cnt++;
        else
        {
            v.push_back(cnt);
            cnt = 1;
        }
    }
    v.push_back(cnt);

    vector<int> t;
    for (int x : v)
    {
        if (x == k) t.push_back(1);
        else if (x < k) t.push_back(0);
        else t.push_back(2);
    }

    int ans = 0;

    int best = 0;

    for (int i = 0; i < t.size(); )
    {
        if (t[i] == 1)
        {
            int j = i;
            while (j < t.size() && t[j] == 1) j++;

            int len = j - i;

            if (i - 1 >= 0 && t[i - 1] == 2) len++;
            if (j < t.size() && t[j] == 2) len++;

            best = max(best, len);
            i = j;
        }
        else i++;
    }

    if (best > 0)
    {
        cout << best * k;
        return 0;
    }

    bool has2 = false;
    bool twoAdj = false;

    for (int i = 0; i < t.size(); i++)
    {
        if (t[i] == 2) has2 = true;
        if (i + 1 < t.size() && t[i] == 2 && t[i + 1] == 2)
            twoAdj = true;
    }

    if (twoAdj) cout << 2 * k;
    else if (has2) cout << k;
    else cout << 0;

}
