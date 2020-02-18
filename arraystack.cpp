#include <iostream>
/* array stack: all run time tests in main function */

struct ASTACK
{
    int A[1000];
    int length;
};

void POP(ASTACK *S)
{
    if(S->length > 0){
        for(int i=0; i<=S->length; i++){
            S->A[i] = S->A[i+1];} 
        S->length--;
    }
    else{std::cerr << "Stack is empty";}
}

void PUSH(int x, ASTACK *S)
{
    for(int i=S->length; i>=0; i--)
            S->A[i+1] = S->A[i];

        S->A[0] = x;
        S->length++;
}

void MAKENULL(ASTACK *S)
{
    int l = S->length;
    for(int i=1; i<=l; i++){
        POP(S);
    }
}
