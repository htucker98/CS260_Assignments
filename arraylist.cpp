#include <iostream>
#include <time.h>

#include <iostream>
#include <time.h>
/* array: all run time tests in main function */
struct Array
{
      int A[1000000];
      int length;
};

int NEXT(int p, Array *L)
  { /*  return the positions following position p on list L. If p is the last
  position on L, then NEXT(p, L) = END(L). NEXT is undefined if p is END(L). */
      if (p <= L->length && p >= 0)
      {
          p++;
          return p;
      }
      else
      {
          std::cerr << "Index out of bounds";
      }
  }
  int END(Array *L)
  {
      return L->length;
  }

int PREVIOUS(int p, Array *L)
  { /*  return the positions previous position p on list L. PREVIOUS is undefined if p is  */
      if (p <= L->length && p > 0)
      {
          p--;
          return p;
      }
      else
      {
          std::cerr << "Index out of bounds";
      }
  }


void INSERT(int x, int p, Array *L)
    {
        if(p == L->length)
        {
            L->A[p] = x;
            L->length++;
        }
        else if (p < L->length && p>= 0)
        {
            for (int i = L->length - 1; i >= p; i--)
                L->A[i + 1] = L->A[i];

            L->A[p] = x;
            L->length++;
        }
        else
        {
            std::cerr << "Index out of bounds";
        }
    }

int LOCATE(int x, Array *L)
    {
    /* This function returns the position of x on list L. If x appears more than
         once, then the position of the first occurrence is returned */
      for (int i = 0; i <= L->length; i++)
      {
          if (x == L->A[i])
          {
              return i;
          }
      }
      return END(L); /*  If x does not appear at all, then END(L) is returned */
    }

  int RETRIVE(int p, Array *L)
  { /* This function returns the position of x on list L. If x appearsmore than
       once, then the position of the first occurrence is returned */
      if (p <= L->length)
      {
          return L->A[p];
      }
      else
      {
          std::cerr << "Index out of bounds";
      }
  }


void DELETE(int p, Array *L)
  {
      if (L->length >= 0 && p != L->length-1)
      {
          for (int i = p; i < L->length; i++)
          {
              L->A[i] = L->A[i + 1];
          }
          L->length--;
      }
      else if( p == L->length-1){
        L->A[p] = L->A[p +1];
        L->length--;
      }
      else
      {
          std::cerr << "List is empty";
      }
  }

  void MAKENULL(Array *L)
  {
      for (int i = 0; i <= L->length; i++)
          L->A[i] = 0;
      L->length = 0;
  }
