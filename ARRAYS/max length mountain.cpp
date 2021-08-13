#include<iostream>
#include<vector>
using namespace std;

// 1. Identify the peak , whose previous and next is smaller.
// 2. Once identified the peak and start moving backwards and identify the length of smaller elements , same on the right side.

int mountain_Peak(vector<int> a, int n)
{

}


int main()
{
    int n;
    cin>>n;
    vector<int> a;
    int t;
    for (int i = 0; i < n; i++)
    {
        cin>>t;
        a.push_back(t);
    }
    // Brute Force O(n^3)
    cout<<"Brute Force :"<<mountain_Peak(a,n)<<endl;
   

    return 0;
}