#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    static bool sc[55][55];
    memset(sc, 0, sizeof(sc));

    int a, b;
    char p;

    while (cin >> a >> b >> p)
    {
        int w;
        if (p == 'N') w = 0;
        if (p == 'E') w = 1;
        if (p == 'S') w = 2;
        if (p == 'W') w = 3;

        string s;
        cin >> s;

        bool lost = false;

        for (int i = 0; i < (int)s.size(); i++)
        {
            if (s[i] == 'R')
            {
                w = (w + 1) % 4;
            }
            else if (s[i] == 'L')
            {
                w = (w + 3) % 4;
            }
            else if (s[i] == 'F')
            {
                int nowa = a, nowb = b;
                int na = a, nb = b;

                if (w == 0) nb += 1;
                else if (w == 1) na += 1;
                else if (w == 2) nb -= 1;
                else if (w == 3) na -= 1;

                if (na < 0 or na > x or nb < 0 or nb > y)
                {
                    if (sc[nowa][nowb]) continue;

                    sc[nowa][nowb] = true;
                    lost = true;
                    break;
                }
                else
                {
                    a = na;
                    b = nb;
                }
            }
        }

        char ww;
        if (w == 0) ww = 'N';
        if (w == 1) ww = 'E';
        if (w == 2) ww = 'S';
        if (w == 3) ww = 'W';

        cout << a << " " << b << " " << ww;
        if (lost) cout << " LOST";
        cout << "\n";
    }
}
