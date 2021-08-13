#include<iostream>
#include<vector>
using namespace std;

// 1. Identify the peak , whose previous and next is smaller.
// 2. Once identified the peak and start moving backwards and identify the length of smaller elements say x, same on the right side say y.
// 3. Add x and y then do step 2 for another peak.


int max_len_mountain_Peak(vector<int> a, int n)
{
    // O(n) implimentation
    int largest = 0;
    //Starting element cannot be peak , so satrting from 1st element not from 0
    for(int i=1;;i<=n-2;)
    {
        // Check if a[i] is peak or not
        if(a[i]>a[i-1] && a[i]>a[i+1])
        {
            int count = 1;
            // Checking in left direction
            int j=i;
            while(j>=1 and a[j]>a[j-1])
            {
                j--;
                count++;
            }
            // Checking in right while moving forward
            while(i<=n-2 and a[i]>a[i+1])
            {
                i++;
                count++;
            }
            largest = max(largest,count);
        }
        else
        {
            i++;
        }
    }
    return largest;
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
    cout<<"Brute Force :"<<max_len_mountain_Peak(a,n)<<endl;
   

    return 0;
}