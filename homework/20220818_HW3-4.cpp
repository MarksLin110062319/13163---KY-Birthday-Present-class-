13182 - Twenty One
#include <bits/stdc++.h>
#include "function.h"
using namespace std;

Guest::~Guest(){}

Guest::Guest()
{
    name = "";
    money = skill = 0;
}

Guest::Guest(string s, int m, int ski)
{
    name = s;
    money = m;
    skill = ski;
}

string Guest::get_name()
{
    return name;
}

int Guest::get_money()
{
    return money;
}

int Guest::get_skill()
{
    return skill;
}

void Guest::Win(int m)
{
    money += m;
}


Casino::Casino()
{
    fee = 0;
    guest_num = 0;
    income = 0;
    list_num = 0;
}

void Casino::Enterance(int f)
{
    fee = f;
}

void Casino::GuestEnter(string s, int m, int ski)
{
    //已經在賭場
    for(int i = 0; i < guest_num; i++){
        if(guest[i]->get_name() == s)
            return;
    }
    //在黑名單中
    for(int i = 0; i < list_num; i++){
        if(blacklist[i] == s)
            return;
    }
    //確認會不會破產
    if(m <= fee){
        income += m;
        for(int i = 0; i < guest_num; i++){
            if(guest[i]->get_name() == s)
                guest[i]->Win(0);
        }
        blacklist[list_num] = s;
        list_num++;
    }
    else{
        income += fee;
        guest[guest_num] = new Guest(s, m-fee, ski);    //可能有問題?
        guest_num++;
    }
}

void Casino::Win(string s, int m)
{
    //不在賭場
    int emp = 1;
    for(int i = 0; i < guest_num; i++){
        if(guest[i]->get_name() == s)
            emp = 0;
    }
    if(emp)
        return;
    //在黑名單中
    for(int i = 0; i < list_num; i++){
        if(blacklist[i] == s)
            return;
    }

    for(int i = 0; i < guest_num; i++){
        if(guest[i]->get_name() == s){
            if(m > 0){
                guest[i]->Win(m);
                income -= m;
                if(m > guest[i]->get_skill() * 2){
                    blacklist[list_num] = s;
                    list_num++;
                }
            }

            else if(m < 0){
                if(guest[i]->get_money() - abs(m) < 0){
                    income += guest[i]->get_money();
                    guest[i]->Win(0);
                    blacklist[list_num] = s;
                    list_num++;
                }
                else{
                    guest[i]->Win(m);
                    income -= m;
                    if(m > guest[i]->get_skill() * 2){
                        blacklist[list_num] = s;
                        list_num++;
                    }
                }
            }
        }
    }

}

void Casino::EndDay()
{
    for(int i = 0; i < guest_num; i++){
        if(guest[i]){
            delete guest[i];
            guest[i] = NULL;
        }
    }
    fee = 0;
    guest_num = 0;
}

void Casino::Result()
{
    cout << income << endl;
    for(int i = 0; i < list_num; i++){
        cout << blacklist[i] << endl;
    }

    for(int i = 0; i < list_num; i++){
        blacklist[list_num].clear();
    }
}

Casino::~Casino(){}


