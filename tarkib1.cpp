#include <iostream>
using namespace std;

int com(int n , int r)
{
    if (r==0 || r==n)
        return 1;
    else
        return com(n-1 , r-1)+com(n-1 , r);

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
    cout<<"com c("<<n<<","<<r<<")="<<com(n,r)<<endl;
}

return 0;
}