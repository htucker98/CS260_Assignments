#include <iostream>
#include <time.h>
#include "arraylist.cpp"
#include <list>
#include <stack>       

int main()
 {
     /* Array tests */
    Array *L = new Array;
    L->length = 0;

    clock_t;
    /* time insertion in front */
    double t = clock();
    for (int i = 1; i < 100; i++)
    {
        INSERT(i, 0, L);
    }
    t = clock() - t;
    double t_in_sec = (t) / CLOCKS_PER_SEC;
    std::cout << "Insertion in front: " << t_in_sec << "\n";

    for (int i = 0; i < L->length; i++)
    {
        std::cout << L->A[i] << " ";
    }

    /* time insertion in back */
    Array *L = new Array;
    t = clock();
    for (int i = 1; i < 100; i++)
    {
        int l = L->length;
        INSERT(i, l, L);
    }
    t = clock() - t;
    t_in_sec = (t) / CLOCKS_PER_SEC;
    std::cout << "\nInsertion in back array: " << t_in_sec << "\n";

    for (int i = 0; i < L->length; i++)
    {
        std::cout << L->A[i] << " ";
    }

    /* time transversal */
    t = clock();
    for (int i = 0; i <= L->length; i++)
    {
        L->A[i];
    }
    t = clock() - t;
    t_in_sec = (t) / CLOCKS_PER_SEC;
    std::cout << "\nTransversal of array: " << t_in_sec << "\n";

    for (int i = 0; i < L->length; i++)
    {
        std::cout << L->A[i] << " ";
    }

    /* deletion from front */
    t = clock();
    int len = L->length;
    for (int i = 0; i <= len; i++)
    {
        DELETE(0, L);
    }
    t = clock() - t;
    t_in_sec = (t) / CLOCKS_PER_SEC;
    std::cout << "\nDeletion from front: " << t_in_sec << "\n";

    for (int i = 0; i < L->length; i++)
    {
        std::cout << L->A[i] << " ";
    }

    /* deletion from back */
    for (int i = 1; i < 100; i++)
    {
        int l = L->length;
        INSERT(i, l, L);
    }
    t = clock();
    int l = L->length;
    for (int i = 0; i <= l; i++)
    {
        DELETE(0, L);
    }
    t = clock() - t;
    t_in_sec = (t) / CLOCKS_PER_SEC;
    std::cout << "\nDeletion from back: " << t_in_sec;

    for (int i = 0; i < L->length; i++)
    {
        std::cout << L->A[i] << " ";
    }
 }