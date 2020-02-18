#include <iostream>
/* linked list: all run time tests in main function */
struct NODE {
    int val;
    NODE* next;
};

struct LIST
{
NODE *head;
NODE *tail;   
};

void INSERT(int x, int p, LIST *L)
{
    NODE *prv=new NODE;
    NODE *cur=new NODE;
    NODE *tmp=new NODE;
    cur=L->head;
    int i=0;
    while(i<p && cur->next != NULL){
        prv=cur;
        cur=cur->next;
        i++;
    }
    if(p==i+1 && cur->next == NULL){
        tmp->val=x;
        tmp->next=NULL;
        cur->next=tmp;
        L->tail=tmp;
    }
    else if(p==0){
        cur=L->head;
        tmp->val=x;
        tmp->next=cur;
        L->head=tmp;
    }
    else if(p==i){
        tmp->val=x;
        prv->next=tmp;
        tmp->next=cur;
    }
}

int END(LIST *L)
{
    NODE *tmp=new NODE;
    int i=0;
    tmp=L->head;
    while(tmp->next != L->tail){
        tmp=tmp->next;
        i++;
    }
    i++;
    return i;
}

int FIRST(LIST *L)
{
    if (L->head->next != NULL){
        return 0;
    }
    else{
        return -1;
    }
}

int LOCATE( int x, LIST *L)
{
    NODE *tmp=new NODE;
    int i=0;
    tmp=L->head;
    while(tmp->val != x && tmp->next!=NULL){
        tmp=tmp->next;
        i++;
    }
    if (tmp->next == NULL && tmp->val != x){
        return -1;
    }
    else if (tmp->val != x){
        return -1;
    }
    else{
        return i;
    }
}
int DELETE(int p, LIST *L)
{
    NODE *tmp=new NODE;
    NODE *prev=new NODE;
    int i=0;
    tmp=L->head;
    while(i<p && tmp->next != NULL){
        prev=tmp;
        tmp=tmp->next;
        i++;
    }
    if (p == 0){
        tmp=tmp->next;
        L->head=tmp;
    }
    else if (i == p-1 && tmp->next == NULL){
        prev->next=NULL;
    }
    else if (i == p-1){
        prev->next=tmp->next;
    }
    
}

int RETRIVE(int p, LIST *L)
{
    NODE *tmp=new NODE;
    int i=0;
    tmp=L->head;
    while(i<p && tmp != NULL){
        tmp=tmp->next;
        i++;
    }
    if (i == p){
        int x = tmp->val;
        return x;
    }
    else{
        return -1;
    }
}

int NEXT(int p, LIST *L)
{
    NODE *tmp=new NODE;
    int i=0;
    tmp=L->head;
    int e = END(L);
    while(i<p && i<e){
        tmp=tmp->next;
        i++;
    }
    if(i==p && i<e){
        i++;
        return i;
    }
    else{
        return -1;
    }
    
}

int PREVIOUS(int p, LIST *L)
{
    NODE *tmp=new NODE;
    int i=0;
    tmp=L->head;
    int e = END(L);
    while(i<p && i<= e){
        tmp=tmp->next;
        i++;
    }
    if (i==p && i!=0 && i<=e){
        i--;
        return i;
    }
    else{
        return -1;
    }
    
}

void MAKENULL(LIST *L)
{
    L->head=NULL;
    L->tail=NULL;
}

void display(LIST *L)
{
NODE *tmp=new NODE;
tmp=L->head;
while(tmp!=NULL)
{
    std::cout<<tmp->val<<" ";
    tmp=tmp->next;
}
} 

