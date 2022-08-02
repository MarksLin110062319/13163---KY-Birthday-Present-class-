#include <bits/stdc++.h>
using namespace std;

bool is_recursive(string first_letter, string first_str)
{
    for(int i = 0; i < first_letter.size(); i++){
        first_letter[i] = tolower(first_letter[i]);
    }
    for(int i = 0; i < first_str.size(); i++){
        first_str[i] = tolower(first_str[i]);
    }

    if(first_letter == first_str)
        return true;
    else
        return false;
}

int main()
{
    string input;
    while(getline(cin, input)){
        string store;
        string store_list[3000];
        string ans;
        stringstream ss(input);
        int idx = 0;

        while(getline(ss, store, ' ')){
            store_list[idx] = store;
            ans = ans + store_list[idx][0];
            idx++;
        }
        if(is_recursive(ans, store_list[0]))
            cout << "o'_'o" << endl;
        else
            cout << "QQ" << endl;

    }
    return 0;
}
