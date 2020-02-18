#include <iostream>
/* linked list stack: all run time tests in main function */
struct node {
    int val;
    node* next;
};

struct STACK
{
node *top; 
};

void POP(STACK *S)
{
    if(S->top == NULL){
        std::cerr << "/nStack is empty";
    }
    else{
        node *tmp=new node;
        tmp=S->top;
        S->top= S->top->next;
        delete(tmp);
    }
}

node* TOP(STACK *S)
{
    return S->top;
}

void PUSH(int x, STACK *S)
{
    node *tmp=new node;
    node *cur=new node;
    cur=S->top;
    tmp->val=x;
    tmp->next=cur;
    S->top=tmp;
}

void MAKENULL(STACK *S)
{
    while(S->top != NULL){
        POP(S);
    }
}

bool EMPTY(STACK *S)
{
    if (S->top == NULL){
        return true;
    }
    else{
        return false;
    }
}

void display(STACK *S)
{
node *tmp=new node;
tmp=S->top;
while(tmp!=NULL)
{
    std::cout<<tmp->val<<" ";
    tmp=tmp->next;
}
} 
