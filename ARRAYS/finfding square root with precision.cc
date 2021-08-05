#include<iostream>

using namespace std;

float squareroot(int n)
{
    int s=0,e=n,mid;
    float ans;
    //This loop is for integral part
    while(s<=e)
    {
        mid = s+(e-s)/2;
        if(mid*mid == n)
        {
            ans = mid;
            break;
        }
        if(mid*mid<n)
        {
            s=mid+1;
            ans = mid;
        }
        else
        e =mid-1;
    }

    //Now fractional part , we can use the given precision too , we have taken p as precision value
    float inc=0.1;
    int p=5; //Took precision uptil 5 decimal places
    for(int i=0;i<p;i++)
    {
        while (ans*ans <= n)
        {
            ans+=inc;
        }
        ans = ans-inc; //Here answer is 0.1(inc) greater than orignal
        inc = inc/10; // This is for next decimal value 
    } 
    return ans;
}




int main()
{
    int n;cin>>n;
    cout<<"Square root is : "<<squareroot(n)<<endl;


    return 0;
}