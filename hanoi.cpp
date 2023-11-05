#include<iostream>
#include<math.h>
using namespace std;

void hanoi(int nhalghe , char mabda , char temp , char maghsad)
{
    if (nhalghe==1)
    { 
        cout<<"harekate halghe 1 az "<<mabda<<" be "<<maghsad<<endl;
    }
    else
    {
        hanoi( nhalghe-1 , mabda , maghsad , temp );
        cout<<"harekat halghe "<<nhalghe<<" az "<<mabda<<" be "<<maghsad<<endl;
        hanoi(nhalghe-1 , temp , maghsad , mabda);

    }       
}

int main()
{
    int n;
    cout<<"num of halghe : ";
    cin>>n;
    hanoi(n , 'A' , 'B', 'C');

    return 0;
}