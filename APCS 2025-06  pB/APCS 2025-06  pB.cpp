// god damn 那時去考沒寫出來 我的分數啊啊啊啊
// 我覺得我寫的很簡單誒 但可讀性低所以下面會有全註解
#include <iostream>
#include <string>
using namespace std;
int main() 
{
    int m, n, k;
    cin >> m >> n >> k;
    string str[m];
    for (int i = 0; i < m; ++i) cin >> str[i];
    int ans = 0;  
    // 下面的轉換次數(我現在想到可以把全部轉換次數加起來在去%應該可以減少時間)
    for (int round = 0; round < k; ++round) 
    {
        int op[m];
        for (int j = 0; j < m; ++j) 
        {
            cin >> op[j];
            if (op[j] == 0) continue;

            string s = str[j];
            if (op[j] > 0)  // >0 就把尾巴往頭去塞
            {
                int r = op[j] % n;                    
                if (r) str[j] = s.substr(n - r, r) + s.substr(0, n - r);
            } 
            else // <0 就把頭塞到尾巴
            { 
                int r = (-op[j]) % n;                
                if (r) str[j] = s.substr(r, n - r) + s.substr(0, r);
            }
        }

        // 這邊我就用土炮的方法去解分數的部分
        int round_score = 0;
        for (int col = 0; col < n; ++col) 
        {
            int a[26];
            for (int t = 0; t < 26; ++t) a[t] = 0;   

            for (int row = 0; row < m; ++row) 
            {
                char c = str[row][col];
                if (c == 'a') a[0]++;
                else if (c == 'b') a[1]++;
                else if (c == 'c') a[2]++;
                else if (c == 'd') a[3]++;
                else if (c == 'e') a[4]++;
                else if (c == 'f') a[5]++;
                else if (c == 'g') a[6]++;
                else if (c == 'h') a[7]++;
                else if (c == 'i') a[8]++;
                else if (c == 'j') a[9]++;
                else if (c == 'k') a[10]++;
                else if (c == 'l') a[11]++;
                else if (c == 'm') a[12]++;
                else if (c == 'n') a[13]++;
                else if (c == 'o') a[14]++;
                else if (c == 'p') a[15]++;
                else if (c == 'q') a[16]++;
                else if (c == 'r') a[17]++;
                else if (c == 's') a[18]++;
                else if (c == 't') a[19]++;
                else if (c == 'u') a[20]++;
                else if (c == 'v') a[21]++;
                else if (c == 'w') a[22]++;
                else if (c == 'x') a[23]++;
                else if (c == 'y') a[24]++;
                else if (c == 'z') a[25]++;
            }

            int mx = 0;
            for (int t = 0; t < 26; ++t)
                if (a[t] > mx) mx = a[t];
            round_score += mx;
        }

        ans += round_score;  
        
    }

    cout << ans << endl;
}
