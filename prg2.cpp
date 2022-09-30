#include <bits/stdc++.h>
using namespace std;
int quicksort(int number[25],int first,int last){
   int i, j, pivot, temp,m,n;
int c=0;
   if(first<last){
      pivot=first;
      i=first;
      j=last;
      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            {i++; c++;}
         while(number[j]>number[pivot])
           { j--; c++;}
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      
      m= quicksort(number,first,j-1);
     n=quicksort(number,j+1,last);
     return c+n+m;
   }
}

int main(){
 int size = 32;
    int a[30000];
    int m;
    cout << "Size    "
         << "Asc   C*n^n   "
         << "dsc    C*n^n "
         << "random     C*nlog(n)" << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << size << "\t";
        for (int j = 0; j < size; j++)
        {
            a[j] = j;
        }
        m = quicksort(a, 0, size - 1);
        cout << m << "\t" << 3 * size * log2(size) << "\t";
        for (int j = 0; j < size; j++)
        {
            a[j] = size - j;
        }
        m = quicksort(a, 0, size - 1);
        cout << m << "\t" << 3 * size * log2(size) << "\t  ";
        for (int j = 0; j < size; j++)
        {
            a[j] = rand() % 10000;
        }
        m = quicksort(a, 0, size - 1);
        cout << m << "\t\t" << 3 * size * log2(size) << "\t";
        size = size * 2;
        cout << endl;
    }

   return 0;
}