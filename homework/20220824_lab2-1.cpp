13454 - Circular String
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string now_s = s;
    int cnt = s.size();
    while(cnt--){
        string c = s.substr(0, 1);
        s = s.substr(1, s.size()-1);
        s = s + c;

        if(s < now_s)
            now_s = s;
    }
    cout << now_s << endl;
}
