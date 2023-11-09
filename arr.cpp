#include<iostream>
#include<math.h>
using namespace std;

void insert(int a[] , int m , int k , int x)        //تعداد شیفت مورد نظر : m-k
{
    for(int i=m-1 ; i>=k ; i--)
        a[i+1]=a[i];
    a[k]=x;
}

void delete(int a[] , int n , int k , int x)
{
    x=a[k];
    for(int i=k ; i<n ; i++)
        a[i]=a[i+1];
    a[i]=0;
    return(x);
}

int find(int a[] , int n , int x) //n=سایز
{
    for(int i=0 ; i<n ; i++)
    {
        if(a[i]==x)
        {
            return i;
        }
    }
    return -1;
}
