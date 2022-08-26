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
    if(!this->reverse){
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
    else{
        Node *newnode = (Node*)malloc(sizeof(Node));
        newnode->val = x;
        newnode->prev = NULL;
        newnode->next = this->tail;
        this->tail->prev = newnode;
        this->tail = newnode;
        this->sz++;
        if(this->sz % 2 != 0)
            this->mid = this->mid->prev;
        return;
    }
}

void KuoYangPresent::Pop()
{
    if(!this->reverse){
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
    else{
        Node *current = this->mid;
        Node *nextone = current->next;
        this->sz--;
        if(this->sz % 2 == 0)
            this->mid = nextone;
        else if(this->sz % 2 != 0)
            this->mid = current->prev;

        nextone->prev = current->prev;
        current->prev->next = nextone;
        free(current);
        current = NULL;
        return;
    }
}

Node *lef = NULL;
Node *rig = NULL;

void KuoYangPresent::ProgrammingTanoshi()
{
    Node* pos = NULL;
    if(lef == NULL || rig == NULL){
        pos = this->head;
        while(pos != NULL){
            pos->val %= k;
            if(!this->reverse){
                pos = pos->next;
                lef = this->head;
                rig = this->tail;
            }
            else{
                pos = pos->prev;
                lef = this->tail;
                rig = this->head;
            }
        }
    }
    else{
        pos = lef;
        while(pos != NULL){
            pos->val %= k;
            pos = pos->prev;
        }
        pos = rig;
        while(pos != NULL){
            pos->val %= k;
            pos = pos->next;
        }
        if(!this->reverse){
            lef = this->head;
            rig = this->tail;
        }
        else{
            lef = this->tail;
            rig = this->head;
        }
    }
}

void KuoYangPresent::Reverse()
{
    Node *temp = NULL;
    temp = this->head;
    this->head = this->tail;
    this->tail = temp;
    if(this->sz % 2 == 0){
        if(!this->reverse)
            this->mid = this->mid->next;
        else
            this->mid = this->mid->prev;
    }

    if(this->reverse)
        this->reverse = false;
    else
        this->reverse = true;
}

void KuoYangPresent::KuoYangTeTe(){}

void KuoYangPresent::PrintList()
{
    if(!this->reverse){
        Node* nownode = this->head;
        while(nownode != NULL){
            cout << nownode->val << " ";
            nownode = nownode->next;
        }
        cout << endl;
    }
    else{
        Node* nownode = this->head;
        while(nownode != NULL){
            cout << nownode->val << " ";
            nownode = nownode->prev;
        }
        cout << endl;
    }
}

