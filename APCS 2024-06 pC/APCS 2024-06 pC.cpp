#include <iostream>
#include <string>
#include <set>
using namespace std;

string k, s;
int l;
set<string> st;


void dfs(string add) 
{
    if (add.length() == l) 
    {
        st.insert(add);
        return;
    }
    for (int i = 0; i < k.length(); i++) 
    {
    	dfs(add+k[i]);
    }
}

int main()
{
	cin >> k;
	cin >> l;
	cin >> s;
	
	dfs("");
	
	
	for (int i = 0; i <= s.length() - l; i++)
	{
		string ss = s.substr(i, l);
		if (st.find(ss) != st.end())
		{
			st.erase(ss);
		}
	}
	
	cout << *st.begin();
}





/* dfs + set取算(可以用substr可以壓縮) */
