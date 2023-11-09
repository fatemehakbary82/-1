#include <iostream>
using namespace std;

int tarkib(int n , int r)
{
    if (r==0 || r==n)
        return 1;
    else
        return tarkib(n-1 , r-1)+tarkib(n-1 , r);

}

int main()
{
    int n,r;
    cout<<"Enter n : ";
    cin>>n;
    cout<<"Enter r:";
    cin>>r;

    if(n<r)
    {
        cout<<"n shoud biger than or equl r"<<endl;
    }
else
{
    cout<<"tarkib c("<<n<<","<<r<<")="<<tarkib(n,r)<<endl;
}

return 0;
}
