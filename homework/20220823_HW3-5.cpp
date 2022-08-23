13464 - Compare strings or characters
#include <bits/stdc++.h>
#include "function.h"
using namespace std;


int cmp(const string &s, const string &t)
{
    if(s > t)
        return 1;
    else if(s == t)
        return 0;
    else
        return -1;
}

int cmp(const string &s, const string &t, int n)
{
    string s_sub = s.substr(0, n);
    string t_sub = t.substr(0, n);

    if(s_sub > t_sub)
        return 1;
    else if(s_sub == t_sub)
        return 0;
    else
        return -1;
}

int cmp(const string &s, char c)
{
    string t;
    t.push_back(c);

    if(s > t)
        return 1;
    else if(s == t)
        return 0;
    else
        return -1;
}

int cmp(char c, const string &s)
{
    string t;
    t.push_back(c);

    if(t > s)
        return 1;
    else if(s == t)
        return 0;
    else
        return -1;
}

int cmp(char c, const string &s, int n)
{
    string t;
    t.push_back(c);
    string s_sub = s.substr(n, 1);

    if(t > s_sub)
        return 1;
    else if(s_sub == t)
        return 0;
    else
        return -1;
}

int cmp(const string &s, char c, int n)
{
    string t;
    t.push_back(c);
    string s_sub = s.substr(n, 1);

    if(s_sub > t)
        return 1;
    else if(s_sub == t)
        return 0;
    else
        return -1;
}

int cmp(char c, char d)
{
    string str_c;
    str_c.push_back(c);
    string str_d;
    str_d.push_back(d);

    if(str_c > str_d)
        return 1;
    else if(str_c == str_d)
        return 0;
    else
        return -1;
}

