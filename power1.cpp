#include<iostream>
#include<math.h>
using namespace std;

int power(int paye , int tavan)
{
    if(tavan==0)
    {
        return 1;
    }
else
{
    return paye * power(paye , tavan-1);
}
}

int main()
{
    int paye , tavan;
    cout<<"paye:";
    cin>>paye;
    cout<<"tavan:";
    cin>>tavan;
    cout<<paye<<" be taven "<<tavan<<" mishavad :  "<<power(paye , tavan)<<endl;

    return 0;
}
