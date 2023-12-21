#include <bits/stdc++.h>
using namespace std; 

void quicksort(int a[], int s, int e)  //ما آرایه را partition میکنیم و بر اساس pivot بقیه آرایه را مرتب میکنیم
 {
        if(s>=e)
            return;
        int q = partition(a,s,e);
        quicksort(a, s, q-1);
        quicksort(a, q+1, e);
 
}
 
int partition(int a[], int s, int e)  //ابتدا عنصر آخر را pivot میگیریم سپس خانه های کوچکتر از آن را از اول آرایه شروع به چیدن میکنیم
{
        int x = a[e];
        int i = s-1;
        for(int j = s;j<e;++j)
        {
            if(a[j]<=x)
            {
                ++i;
                int temp = a[i];
                a[i]= a[j];
                a[j]=temp;
            }
        }
        ++i;
        int temp = a[i];
        a[i]= a[e];
        a[e]=temp;
        return i;
    }