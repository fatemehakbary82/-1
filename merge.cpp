#include<iostream>
using namespace std;

void merge(int * a, int * aux, int lo, int mid, int hi)  //این متد دو آرایه را ادغام میکند
{
 
    for (int k = lo; k <= hi; k++) 
    {
        aux[k] = a[k];
    }
 
    int i = lo, j = mid + 1;
    for (int k = lo; k <= hi; k++) 
    {
        if (i > mid)
            a[k] = aux[j++];
        else if (j > hi)
            a[k] = aux[i++];
        else if (aux[j] < aux[i])
            a[k] = aux[j++];
        else
            a[k] = aux[i++];
    }
 
}  //دو آرایه ما یکی از اندیس low تا mid آرایه اصلی هستند و دیگری از mid تا high آرایه اصلی هستند(متغیر low و mid و high ورودی های ما هستند) سپس نتیجه را در آرایه کمکی به نام aux میریزد.

void sort(int * a, int *aux, int lo, int hi) // فقط آرایه میگیرد و کل آن را مرتب میکند
{
    if (hi <= lo)
        return;
    int mid = lo + (hi - lo) / 2;
    sort(a, aux, lo, mid);
    sort(a, aux, mid + 1, hi);
    merge(a, aux, lo, mid, hi);
}
 
void sort(int *a, int arrsize)  //آرایه و اندیس های ابتدا و انتهایی را ورودی میگیرد تا فقط بین این اندیس ها آرایه را مرتب کند
{
    int aux[arrsize];
    sort(a, aux, 0, arrsize - 1);
 
}