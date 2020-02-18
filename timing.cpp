#include <iostream>
#include <time.h>
#include "arraylist.cpp"
#include "pointerlist.cpp"
#include "arraystack.cpp"
#include "pointerstack.cpp"
#include <list>
#include <stack>
#include <iostream>
#include <time.h>

int main()
   {
      std::cout << "*****Timing for arraylist*****\n\n";
      /* Array tests */
      Array *L = new Array;
         L->length = 0;

      /* time insertion in front */
      double t = clock();
      for (int i = 1; i < 1500; i++)
      {
          INSERT(i, 0, L);
      }
      t = clock() - t;
		double t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
      std::cout << "arraylist insertion in front: " << t_in_sec << " miliseconds\n";

      std::cout << "\n-----------------------------------------------------\n";

       /* time insertion in back */
        Array *L2 = new Array;
        t = clock();
        for (int i = 0; i < 1500; i++)
        {

            INSERT(i+1, i, L2);
        }
        t = clock() - t;
		  t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
        std::cout << "\narraylist insertion in back: " << t_in_sec << " miliseconds\n";

      std::cout << "\n-----------------------------------------------------\n";
      /* time transversal */
      t = clock();
      for (int i = 0; i < L->length; i++)
      {
         L->A[i]; 
      }
      t = clock() - t;
     	t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
	  	std::cout << "\narraylist transversal: " << t_in_sec << " miliseconds\n";
      std::cout << "\n-----------------------------------------------------\n";

      /* deletion from front */
      int len = L->length;
      t = clock();
      for (int i = 0; i < len; i++)
      {
          DELETE(0, L);
      }
      t = clock() - t;
		t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
      std::cout << "\narraylist deletion from front: " << t_in_sec << " miliseconds\n";
      std::cout << "\n-----------------------------------------------------\n";
		/* deletion from back */
      t = clock();
      for (int i=1; i <1500; i++)
      {  int l = L2->length-1;
          DELETE(l, L2);
      }
      t = clock() - t;
		t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
      std::cout << "\narraylist deletion from back: " << t_in_sec << " miliseconds\n";
      std::cout << "\n-----------------------------------------------------\n";
		
		std::cout << "*****Timing for pointerlist*****\n\n";

		LIST *L3=new LIST;
    	/* time insertion in front */
    	t = clock();
     	for (int i=1; i<1500; i++){
         INSERT(i,0,L3);
     	}
    	t = clock()-t;
		t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
      std::cout << "\npointerlist insertion in front: " << t_in_sec << " miliseconds\n";
		std::cout << "\n-----------------------------------------------------\n";	
    	
		/* time insertion at back */
    	MAKENULL(L3);
    	t = clock();
    	for (int i=1; i<1500; i++){

         INSERT(i,i-1,L3);
     	}
     	t = clock()-t;
		t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
     	std::cout << "\npointerlist insertion in back: " << t_in_sec << " miliseconds\n";
      std::cout << "\n-----------------------------------------------------\n";  

		/* transversal through linked list */
     	NODE *tmp = new NODE;
     	tmp=L3->head;
     	t = clock();
     	while(tmp != NULL){
         tmp=tmp->next;
     	}
    	t = clock()-t;
		t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
    	std::cout << "\npointerlist transversal: " << t_in_sec << " miliseconds\n";
      std::cout << "\n-----------------------------------------------------\n";  
		/* deletion from the front linked list */
    	t = clock();
    	while(L3->head != NULL){
        DELETE(0,L3);
    	}
    	t = clock()-t;
		t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
    	std::cout << "\npointerlist deletion from front: " << t_in_sec << " miliseconds\n";
    	std::cout << "\n-----------------------------------------------------\n";  
		/* deletion from the end linked list */
    	for (int i=1; i<1500; i++){
         INSERT(i,0,L3);
    	}
    	t = clock();
    	for(int i=1499; i>=0; i--)
        	DELETE(i,L3);
    	t = clock()-t;
		t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
    	std::cout << "\npointerlist deletion from end: " << t_in_sec << " miliseconds\n";
		std::cout << "\n-----------------------------------------------------\n";

		std::cout << "*****Timing for C++ library list*****\n\n";
		std::list<int> L4;
		t = clock();
		for (int i=1; i<1500; i++){
			L4.push_front(i);
		}
		t = clock()-t;
		t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
		std::cout << "\nC++ builtin list insertion in front: " << t_in_sec << " miliseconds\n";
      std::cout << "\n-----------------------------------------------------\n";		
		L4.clear();
     	t = clock();
     	for (int i=1; i<1500; i++){
         L4.push_back(i);
     	}
     	t = clock()-t;
		t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
		std::cout << "\nC++ builtin list insertion in back: " << t_in_sec << " miliseconds\n";
      std::cout << "\n-----------------------------------------------------\n";

		t = clock();
		for (std::list<int>::iterator it=L4.begin(); it != L4.end(); ++it)
		t = clock()-t;
		t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
		std::cout << "\nC++ builtin list transversal: " << t_in_sec << " miliseconds\n";
      std::cout << "\n-----------------------------------------------------\n";

		/* delete elements from front of list */
    	t = clock();
     	for (int i=1; i<1500; i++){
         L4.pop_front();
     	}
     	t = clock()-t;
		t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
		std::cout << "\nC++ builtin list deletion from front: " << t_in_sec << " miliseconds\n";
        std::cout << "\n-----------------------------------------------------\n";
    /* delete elements from back of list */
    for (int i=1; i<1500; i++){
         L4.push_back(i);
     }
     t = clock();
     for (int i=1; i<1500; i++){
         L4.pop_back();
     }
     t = clock()-t;
	  t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
std::cout << "\nC++ builtin list deletion from back: " << t_in_sec << " miliseconds\n";
          std::cout << "\n-----------------------------------------------------\n";


std::cout << "*****Timing for arraystack*****\n\n";

ASTACK *S=new ASTACK;
    S->length=0;
    /* time PUSH() */
    t = clock();
    for (int i=1; i<=1499; i++)
    {
        PUSH(i,S);
    }
    t = clock() - t;
	 t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
std::cout << "\narraystack PUSH(): " << t_in_sec << " miliseconds\n";
            std::cout << "\n-----------------------------------------------------\n";

     /* time POP() */
     t = clock();
     for (int i=1; i<=1499; i++)
    {
        POP(S);
    }
    t = clock() - t;
	 t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
std::cout << "\narraystack POP(): " << t_in_sec << " miliseconds\n";
            std::cout << "\n-----------------------------------------------------\n";
  std::cout << "*****Timing for pointerstack*****\n\n";

STACK *S2 = new STACK;
    S2->top=NULL;
    /* time PUSH() */
    t = clock();
    for (int i=1; i<=1499; i++)
    {
        PUSH(i,S2);
    }
    t = clock() - t;
	 t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
std::cout << "\npointerstack PUSH(): " << t_in_sec << " miliseconds\n";
              std::cout << "\n-----------------------------------------------------\n";


     /* time POP() */
     t = clock();
     for (int i=1; i<=1499; i++)
    {
        POP(S2);
    }
    t = clock() - t;
	 t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
std::cout << "\npointerstack POP(): " << t_in_sec << " miliseconds\n";
              std::cout << "\n-----------------------------------------------------\n";

  std::cout << "*****Timing for C++ builtin stack*****\n\n";
std::stack<int> S3;


    /* time PUSH() */
    t = clock();
    for (int i=1; i<=1499; i++)
    {
        S3.push(i);
    }
    t = clock() - t;
	 t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
    std::cout << "\nC++ Stack PUSH(): " << t_in_sec << " miliseconds\n";
                std::cout << "\n-----------------------------------------------------\n";


    /* time POP() */
    t = clock();
    for (int i=1; i<=1499; i++)
    {
        S3.pop();
    }
    t = clock() - t;
	 t_in_sec = (1000 * ( t / CLOCKS_PER_SEC ));
std::cout << "\nC++ stack POP(): " << t_in_sec << " miliseconds\n";
                std::cout << "\n-----------------------------------------------------\n";


}
