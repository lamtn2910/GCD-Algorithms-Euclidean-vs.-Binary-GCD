#include <iostream>
#include <algorithm>
using namespace std;

unsigned int BinaryGCD(int a,int b)
{
    if(a==0) return b;
    if(b==0) return a;
    int Count2=0;
    while(a%2==0 && b%2==0)
    {
        a/=2;
        b/=2;
        Count2++;
    }
    while(a%2==0)
    {
        a/=2;
    }
    do
    {
        while(b%2==0)
        {
            b/=2;
        }
        if(a>b) swap(a,b);
        b-=a;
    }while(b!=0);
    return a*(1<<Count2);
}
int main()
{
    
}