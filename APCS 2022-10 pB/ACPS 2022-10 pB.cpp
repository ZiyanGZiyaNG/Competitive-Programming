#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Block { int dr, dc; };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r, c, n;
    cin >> r >> c >> n;

    // ❗改這裡：不要用 VLA
    vector<vector<bool>> g(r, vector<bool>(c, false));

    int quike = 0;
    long long used = 0;

    auto canPlace = [&](int y, Block b[], int m, int xRight) -> bool {
        for (int i = 0; i < m; i++) {
            int rr = y + b[i].dr;
            int cc = xRight - b[i].dc;
            if (rr < 0 || rr >= r || cc < 0 || cc >= c) return false;
            if (g[rr][cc]) return false;
        }
        return true;
    };

    auto place = [&](int y, Block b[], int m, int xRight) {
        for (int i = 0; i < m; i++) {
            int rr = y + b[i].dr;
            int cc = xRight - b[i].dc;
            if (!g[rr][cc]) {
                g[rr][cc] = true;
                used++;
            }
        }
    };

    for (int i = 0; i < n; i++) {
        char t;
        int y;
        cin >> t >> y;

        Block b[8];
        int h = 0, m = 0;

        if (t == 'A') {
            h = 4; m = 4;
            b[0]={0,0}; b[1]={1,0}; b[2]={2,0}; b[3]={3,0};
        } else if (t == 'B') {
            h = 1; m = 3;
            b[0]={0,0}; b[1]={0,1}; b[2]={0,2};
        } else if (t == 'C') {
            h = 2; m = 4;
            b[0]={0,0}; b[1]={0,1}; b[2]={1,0}; b[3]={1,1};
        } else if (t == 'D') {
            h = 2; m = 4;
            b[0]={0,0};
            b[1]={1,0}; b[2]={1,1}; b[3]={1,2};
        } else if (t == 'E') {
            h = 3; m = 5;
            b[0]={0,0};
            b[1]={1,0}; b[2]={1,1};
            b[3]={2,0}; b[4]={2,1};
        } else {
            quike++;
            continue;
        }

        if (y < 0 || y + h > r) {
            quike++;
            continue;
        }

        int x = c - 1;

        if (!canPlace(y, b, m, x)) {
            quike++;
            continue;
        }

        while (x - 1 >= 0 && canPlace(y, b, m, x - 1)) {
            x--;
        }

        place(y, b, m, x);
    }

    long long empty = 1LL * r * c - used;
    cout << empty << " " << quike;
    return 0;
}
