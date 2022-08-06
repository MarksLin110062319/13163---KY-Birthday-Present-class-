//13163 - KYてぇてぇ — Birthday Present（class）
#include <iostream>
#include <string>
#include <bits/stdc++.h>
#include "function.h"
using namespace std;

KuoYangPresent::KuoYangPresent(int k)
{
    this->k = k;
    this->sz = 0;
    this->tail = this->head = this->mid = NULL;
}

void KuoYangPresent::Push(int x)
{
    if(this->tail == NULL){
        Node *newnode = (Node*)malloc(sizeof(Node));
        newnode->val = x;
        newnode->next = newnode->prev = NULL;
        this->tail = this->head = this->mid = newnode;
        this->sz++;
        return;
    }
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->val = x;
    newnode->next = NULL;
    newnode->prev = this->tail;
    this->tail->next = newnode;
    this->tail = newnode;
    this->sz++;
    if(this->sz % 2 != 0)
        this->mid = this->mid->next;
    return;
}

void KuoYangPresent::Pop()
{
    Node *current = this->mid;
    Node *previous = current->prev;
    this->sz--;
    if(this->sz % 2 == 0)
        this->mid = previous;
    else if(this->sz % 2 != 0)
        this->mid = current->next;

    previous->next = current->next;
    current->next->prev = previous;
    free(current);
    current = NULL;
    return;
}

Node *tmp = NULL;

void KuoYangPresent::ProgrammingTanoshi()
{
    Node *target;
    if(tmp == NULL)
        target = this->head;
    else if(tmp != NULL)
        target = tmp->next;
    while(target != NULL){
        target->val %= k;
        //cout << target->val << endl;
        target = target->next;
    }
    tmp = this->tail;
}

void KuoYangPresent::KuoYangTeTe(){}

void KuoYangPresent::PrintList()
{
    Node* nownode = this->head;
    while(nownode != NULL){
        cout << nownode->val << " ";
        nownode = nownode->next;
    }
    cout << endl;
}
