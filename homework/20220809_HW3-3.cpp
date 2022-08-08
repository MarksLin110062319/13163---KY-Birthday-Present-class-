13172 - Powers  
#include <bits/stdc++.h>
#include "function.h"
#define ll long long
using namespace std;

string store;
ll temp;

special_power::special_power(int num)
{
    n = num;
}

int special_power::fpow(int x)
{
    ll tmp = 1;
	for (int i = 0; i < n; ++i) {
		tmp *= x;
		tmp %= 880301;
	}
	return tmp;
}

int special_power::fpow(int x, int m)
{
    ll tmp = 1;
	for (int i = 0; i < n; ++i) {
		tmp *= x;
		tmp %= m;
	}
	return tmp;
}

int special_power::fpow()
{
   ll tmp = 1;
	for (int i = 0; i < n; ++i) {
		tmp *= 2;
		tmp %= 880301;
	}
	return tmp;
}

string special_power::fpow(string s)
{
    string str = "";
    for(int i = 0; i < s.size(); i++){
        string sub_str(n, s[i]);
        str = str + sub_str;
    }
    store = str;
    return str;
}

string special_power::fpow(string s, int m)
{
    string str = store;
    if(str.size() >= m)
        str = str.substr(0, m);
    return str;
}


